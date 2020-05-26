/*
 * VeterinaryBusiness.c
 *  Created on: 21 may. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>

#include "VeterinaryBusiness.h"

#define CREATION_ERROR_MSSG "[ERROR] Hubo un error en la creacion de la entidad\n"
#define CREATION_PET_SUCCESS_MSSG "[SUCESS] Mascota id=%d creada con exito\n"
#define UPDATE_BREED_SUCCESS_MSSG "[SUCESS] Raza id=%d actualizada con exito\n"
#define DELETE_PET_SUCCESS_MSSG "[SUCESS] Mascota id=%d eliminada con exito\n"
#define UPDATE_PET_SUCCESS_MSSG "[SUCESS] Mascota id=%d actualizada con exito\n"
#define UPDATE_OWNER_SUCCESS_MSSG "[SUCESS] Dueño id=%d actualizado con exito\n"
#define CREATE_OWNER_SUCCESS_MSSG "[SUCESS] Dueño id=%d creado con exito\n"
#define DELETE_OWNER_SUCCESS_MSSG "[SUCESS] Dueño id=%d eliminado con exito\n"

#define DELETE_ERROR_MSSG "[ERROR] Hubo un error en la eliminacion de la entidad\n"
#define UPDATE_ERROR_MSSG "[ERROR] Hubo un error en la actualizacion de la entidad\n"
#define CREATE_ERROR_MSSG "[ERROR] Hubo un error en la creacion de la entidad\n"

void vtBsns_initializeAllVeterinary(Veterinary *veterinary){
	veterinary->breedId = 0;
	veterinary->ownerId = 0;
	veterinary->petId = 0;
	breedSvc_initializeAllBreeds(veterinary->breeds, BREEDS_TOP);
	ownerSvc_initializeAllOwners(veterinary->owners, OWNER_TOP);
	petSvc_initializeAllPets(veterinary->pets, PETS_TOP);
}

void vtnBsns_createAPet(Veterinary *veterinary){
	int ownerId;
	int breedId;
	int status;

	utlLb_getBreedHarcdedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getOwnersHarcodedData1(veterinary->owners,&veterinary->ownerId);

	printf("--------------------Crear Mascota-------------------------\n");
	ownerSvc_getValidOwnerId(veterinary->owners,&ownerId,OWNER_TOP); //pido id de dueño existente
	breedSvc_getValidBreedId(veterinary->breeds,&breedId, BREEDS_TOP); //pido id de raza existente

	status = petSv_createPet(veterinary->pets,breedId,ownerId,&veterinary->petId);
	if(status){
		printf(CREATION_PET_SUCCESS_MSSG, veterinary->petId);
		utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
	}else{
		printf(CREATION_ERROR_MSSG);
	}
}

void vtnBsns_updateABreed(Veterinary *veterinary){
	int status;
	utlLb_getBreedHarcdedData1(veterinary->breeds, &veterinary->breedId); //raza

	printf("--------------------Actualizar Raza-------------------------\n");
	status = breedSvc_updateBreed(veterinary->breeds,BREEDS_TOP);
	if(status){
		printf(UPDATE_BREED_SUCCESS_MSSG, veterinary->petId);
		breedSvc_showAllBreeds(veterinary->breeds,BREEDS_TOP);
	}else{
		printf(CREATION_ERROR_MSSG);
	}
}

void vtnBsns_deleteAPet(Veterinary *veterinary){
	int status;
	int petIdDelet;

	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);
	utlLb_getBreedHarcdedData1(veterinary->breeds, &veterinary->breedId);
	printf("--------------------Eliminar Mascota-------------------------\n");

	/*****Join with Breed******/
	do{
		printf("--De las siguiente mascotas selecciones un id valido--\n");
		utilLb_showAllPetsAndTheirBreeds(veterinary->pets,veterinary->breeds,BREEDS_TOP,PETS_TOP);
		scanf("%d",&petIdDelet);
	}while(!petSv_checkValidPetId(veterinary->pets, PETS_TOP,petIdDelet));
	/*************************/
	status = petSv_deletePet(veterinary->pets,petIdDelet,PETS_TOP);
	if(status){
		printf(DELETE_PET_SUCCESS_MSSG);
		utilLb_showAllPetsAndTheirBreeds(veterinary->pets,veterinary->breeds,BREEDS_TOP,PETS_TOP);
	}else
		printf(DELETE_ERROR_MSSG);
}

void vtnBsns_updateAPet(Veterinary *veterinary){
	int status=FALSE;
	int breedUpdId=0;
	int petUpdId=0;
	char updateBreed;

	utlLb_getOwnersHarcodedData1(veterinary->owners,&veterinary->ownerId);
	utlLb_getBreedHarcdedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets,&veterinary->petId);
	printf("--------------------Actualizar Mascota (y su raza)-------------------------\n");

	/*****Join with Breed******/
	do{
		printf("--De las siguiente mascotas selecciones un id valido para su actualizacion--\n");
		utilLb_showAllPetsAndTheirBreeds(veterinary->pets,veterinary->breeds,PETS_TOP, BREEDS_TOP);
		scanf("%d",&petUpdId);
	}while(!petSv_checkValidPetId(veterinary->pets,PETS_TOP,petUpdId));
	/*************************/

	utilLb_getYesNoQuestion("--Desea actualizar tambien la raza de esta mascota [S|N]?:",&updateBreed);

	if(updateBreed=='S'){
		breedSvc_getValidBreedId(veterinary->breeds, &breedUpdId, BREEDS_TOP); //pido nuevo id de razas existente
	}
	status = petSv_updatePet(veterinary->pets,petUpdId,breedUpdId,PETS_TOP);
	if(status){
		printf(UPDATE_PET_SUCCESS_MSSG);
		utilLb_showAllPetsAndTheirBreeds(veterinary->pets,veterinary->breeds,BREEDS_TOP,PETS_TOP);
	}else{
		printf(UPDATE_ERROR_MSSG);
	}
}

void vtnBsns_updateOwner(Veterinary *veterinary){
	int ownerUpdId=0;
	int status;
	utlLb_getOwnersHarcodedData1(veterinary->owners,&veterinary->ownerId);

	printf("--------------------Actualizar Dueño-------------------------\n");
	ownerSvc_getValidOwnerId(veterinary->owners,&ownerUpdId, OWNER_TOP);

	status = ownerSvc_updateOwner(veterinary->owners,OWNER_TOP, ownerUpdId);
	if(status){
		printf(UPDATE_OWNER_SUCCESS_MSSG);
		utilLb_showOwnersOnly(*veterinary,OWNER_TOP);
	}else{
		printf(UPDATE_ERROR_MSSG);
	}
}

void vtnBsns_createOwner(Veterinary *veterinary){
	printf("--------------------Creando Dueño-------------------------\n");
	int status = ownerSvc_createOwner(veterinary->owners,OWNER_TOP, &veterinary->ownerId);
	if(status){
		printf(CREATE_OWNER_SUCCESS_MSSG,veterinary->ownerId);
		utilLb_showOwnersOnly(*veterinary,OWNER_TOP);
	}else{
		printf(CREATE_ERROR_MSSG);
	}
}

void vtnBsns_deleteOwner(Veterinary *veterinary){
	int ownerDelId;
	int status;

	utlLb_getOwnersHarcodedData1(veterinary->owners,&veterinary->ownerId);
	utlLb_getBreedHarcdedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);

	printf("--------------------Borrando Dueño-------------------------\n");
	ownerSvc_getValidOwnerId(veterinary->owners,&ownerDelId, OWNER_TOP);

	status = ownerSvc_deleteOwner(veterinary->owners,OWNER_TOP, ownerDelId);
	if(status){
		printf(DELETE_OWNER_SUCCESS_MSSG,ownerDelId);
		printf("--Borrando las mascotas de este dueño--\n");
		petSv_deletePetByOwnerId(veterinary->pets,ownerDelId, PETS_TOP);
		printf("[SUCESS] Mascota que pertenecen al dueño con id=%d eliminadas con exito\n",ownerDelId);
		utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
	}
}

//Pregunta 9
void vtnBsn_sortPetsByTypeAndShowAll(Veterinary *veterinary){
	utilLb_getHarcodedVeterinaryDataForPetUpdate(veterinary);
	printf("----------ANTES---------------\n");
	utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
	utilLb_sortPetsByType(veterinary->pets, PETS_TOP, 1); //1=ASC 0=DSC
	printf("----------DESPUES-------------\n");
	utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
}
//pregunta 11
void vtnBsn_showOwnerWithPets(Veterinary *veterinary){
	utilLb_getHarcodedVeterinaryDataForPetUpdate(veterinary);
	utilLb_showOwnerThaHavePets(veterinary->owners,veterinary->pets,OWNER_TOP, PETS_TOP);
}
//pregunta 12
void vtnBsn_showPetsMoreThan3YearsAndHisOwner(Veterinary *veterinary){
	utilLb_getHarcodedVeterinaryDataForPetUpdate(veterinary);
	utilLb_showPethsMoreNYearWithOwner(*veterinary,OWNER_TOP, PETS_TOP, BREEDS_TOP, 3);
}
//pregunta 13
void vtnBsn_showPetsByType(Veterinary *veterinary){
	utilLb_getHarcodedVeterinaryDataForPetUpdate(veterinary);
	utilLb_showPetsByType(veterinary->pets,veterinary->breeds,PETS_TOP,BREEDS_TOP, 1);
}
//pregunta 14 y 15
//Ordeno por cant mascotas si esta cantidades son iguales se ordena alfabeticamente por nombre en forma ascendente
void vtnBsn_sortOwnerByPetsNumberAndOwnerName(Veterinary *veterinary){
	int mode = 1; //1=asc 0=dsc
	utilLb_getHarcodedVeterinaryDataForPetUpdate(veterinary);

	printf("--->BEFORE------->:\n");
	utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
	utilLb_sortOwnerByNumberOfPetsAndOwnerName(veterinary->owners,veterinary->pets,OWNER_TOP,PETS_TOP, 1);
	printf("--->AFTER------->:\n");
	utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
}

void vtnBsn_calculateAndShowAllInfo(Veterinary *veterinary){
	utilLb_getHarcodedVeterinaryDataForPetUpdate(veterinary);
	utilLb_calculateAndShowPetsAgeAverage(veterinary->pets,PETS_TOP);
	utilLb_calculatePetsAgeAverageByType(veterinary->pets,PETS_TOP);
	utilLb_calculatePercentageOwnerByGender(veterinary->owners,OWNER_TOP);

	utilLb_showCustomerWithPetsSameGender(veterinary->owners,veterinary->pets,OWNER_TOP,PETS_TOP);
}
//************Private Functions********************


