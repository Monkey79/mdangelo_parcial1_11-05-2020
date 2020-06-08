/*
 * PetTest.c
 *  Created on: 6 jun. 2020
 *  Author: mdagelo
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "../utn_mdangelo_utils/Utils.h"
#include "../utn_mdangelo_service/OwnerService.h"
#include "../utn_mdangelo_service/BreedService.h"
#include "../utn_mdangelo_service/PetService.h"

#include "../utn_mdangelo_commons/CommonsValue.h"

#include "EntitiesTest.h"


int entTst_petCreationTest(Veterinary * pVet){
	int ownerId;
	int breedId;
	int status = SUCCESS;

	utlLb_getBreedHarcodedData1(pVet->breeds, &pVet->breedId); //pido razas harcodeada
	utlLb_getOwnersHarcodedData1(pVet->owners, &pVet->ownerId); //pido dueños harcodeados

	printf("--------------------Crear Mascota-------------------------\n");
	ownerSvc_getValidOwnerId(pVet->owners, &ownerId, OWNER_TOP); //pido id de dueño existente
	breedSvc_getValidBreedId(pVet->breeds, &breedId, BREEDS_TOP); //pido id de raza existente
	status = petSv_createPet(pVet->pets, breedId, ownerId, &pVet->petId);
	if (status) {
		printf(CREATION_PET_SUCCESS_MSSG, pVet->petId);
		utilLb_showOwnersAndTheirPetsWithBreeds(*pVet);
	} else {
		printf(CREATION_ERROR_MSSG);
		status = ERROR;
	}
	return status;
}

int entTst_updateABreedTest(Veterinary *veterinary) {
	int status = SUCCESS;
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId); //pido razas harcodeada

	printf("--------------------Actualizar Raza-------------------------\n");
	status = breedSvc_updateBreed(veterinary->breeds, BREEDS_TOP);
	if (status) {
		printf(UPDATE_BREED_SUCCESS_MSSG, veterinary->petId);
		breedSvc_showAllBreeds(veterinary->breeds, BREEDS_TOP);
	} else {
		status = ERROR;
		printf(CREATION_ERROR_MSSG);
	}
	return status;
}

int entTst_deleteAPetTest(Veterinary *veterinary){
	int petIdDelet;
	int status = SUCCESS;

	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
	printf("--------------------Eliminar Mascota-------------------------\n");

	/*****Join with Breed******/
	do {
		printf("--De las siguiente mascotas selecciones un id valido--\n");
		utilLb_showAllPetsAndTheirBreeds(veterinary->pets, veterinary->breeds,
		BREEDS_TOP, PETS_TOP);
		scanf("%d", &petIdDelet);
	} while (!petSv_checkValidPetId(veterinary->pets, PETS_TOP, petIdDelet));
	/*************************/
	status = petSv_deletePet(veterinary->pets, petIdDelet, PETS_TOP);
	if (status) {
		printf(DELETE_PET_SUCCESS_MSSG);
		utilLb_showAllPetsAndTheirBreeds(veterinary->pets, veterinary->breeds,
		BREEDS_TOP, PETS_TOP);
	} else{
		printf(DELETE_ERROR_MSSG);
		status = ERROR;
	}
	return status;
}

int entTst_updateAPetTest(Veterinary *veterinary){
	int status = FALSE;
	int breedUpdId = 0;
	int petUpdId = 0;
	char updateBreed;

	utlLb_getOwnersHarcodedData1(veterinary->owners, &veterinary->ownerId);
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);
	printf("--------------------Actualizar Mascota (y su raza)-------------------------\n");

	/*****Join with Breed******/
	do {
		printf("--De las siguiente mascotas selecciones un id valido para su actualizacion--\n");
		utilLb_showAllPetsAndTheirBreeds(veterinary->pets, veterinary->breeds,PETS_TOP, BREEDS_TOP);
		scanf("%d", &petUpdId);
	} while (!petSv_checkValidPetId(veterinary->pets, PETS_TOP, petUpdId));
	/*************************/

	utilLb_getYesNoQuestion("--Desea actualizar tambien la raza de esta mascota [S|N]?:", &updateBreed);

	if (updateBreed == 'S') {
		breedSvc_getValidBreedId(veterinary->breeds, &breedUpdId, BREEDS_TOP); //pido nuevo id de razas existente
	}
	status = petSv_updatePet(veterinary->pets, petUpdId, breedUpdId, PETS_TOP);
	if (status) {
		printf(UPDATE_PET_SUCCESS_MSSG);
		utilLb_showAllPetsAndTheirBreeds(veterinary->pets, veterinary->breeds,
		BREEDS_TOP, PETS_TOP);
	} else {
		printf(UPDATE_ERROR_MSSG);
		status = ERROR;
	}
	return status;
}

int entTst_updateOwnerTest(Veterinary *veterinary){
	int ownerUpdId = 0;
	int status = SUCCESS;
	utlLb_getOwnersHarcodedData1(veterinary->owners, &veterinary->ownerId);

	printf("--------------------Actualizar Dueño-------------------------\n");
	ownerSvc_getValidOwnerId(veterinary->owners, &ownerUpdId, OWNER_TOP);

	status = ownerSvc_updateOwner(veterinary->owners, OWNER_TOP, ownerUpdId);
	if (status) {
		printf(UPDATE_OWNER_SUCCESS_MSSG);
		utilLb_showOwnersOnly(*veterinary, OWNER_TOP);
	} else {
		printf(UPDATE_ERROR_MSSG);
		status = ERROR;
	}
	return status;
}

int entTst_createOwnerTest(Veterinary *veterinary) {
	printf("--------------------Creando Dueño-------------------------\n");
	int status = ownerSvc_createOwner(veterinary->owners, OWNER_TOP, &veterinary->ownerId);
	if (status) {
		printf(CREATE_OWNER_SUCCESS_MSSG, veterinary->ownerId);
		utilLb_showOwnersOnly(*veterinary, OWNER_TOP);
	} else {
		printf(CREATE_ERROR_MSSG);
		status = ERROR;
	}
	return status;
}

int entTst_deleteOwner(Veterinary *veterinary){
	int ownerDelId;
	int status;

	utlLb_getOwnersHarcodedData1(veterinary->owners, &veterinary->ownerId);
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);

	printf("--------------------Borrando Dueño-------------------------\n");
	ownerSvc_getValidOwnerId(veterinary->owners, &ownerDelId, OWNER_TOP);

	status = ownerSvc_deleteOwner(veterinary->owners, OWNER_TOP, ownerDelId);
	if (status) {
		printf(DELETE_OWNER_SUCCESS_MSSG, ownerDelId);
		printf("--Borrando las mascotas de este dueño--\n");
		int match = petSv_deletePetByOwnerId(veterinary->pets, ownerDelId, PETS_TOP);
		if(match)
			printf("[SUCESS] Mascota que pertenecen al dueño con id=%d eliminadas con exito\n", ownerDelId);
		else
			printf("[ATENCION]Este dueño NO tenia mascotas\n");
		utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
	}else{
		printf(DELETE_ERROR_MSSG);
		status = ERROR;
	}
	return status;
}

//Pregunta 9
void entTst_sortPetsByTypeAndShowAll(Veterinary *veterinary){
	utlLb_getOwnersHarcodedData1(veterinary->owners, &veterinary->ownerId);
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);
	printf("----------ANTES---------------\n");
	utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
	utilLb_sortPetsByType(veterinary->pets, PETS_TOP, 1); //1=ASC 0=DSC
	printf("----------DESPUES-------------\n");
	utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
}
//pregunta 11
void entTst_showOwnerWithPets(Veterinary *veterinary){
	utlLb_getOwnersHarcodedData1(veterinary->owners, &veterinary->ownerId);
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);

	utilLb_showOwnerThaHavePets(veterinary->owners, veterinary->pets, OWNER_TOP, PETS_TOP);
}
//pregunta 12
void entTst_showPetsMoreThan3YearsAndHisOwner(Veterinary *veterinary){
	utlLb_getOwnersHarcodedData1(veterinary->owners, &veterinary->ownerId);
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);

	utilLb_showPethsMoreNYearWithOwner(*veterinary, OWNER_TOP, PETS_TOP, BREEDS_TOP, 3);
}
//pregunta 13
void entTst_showPetsByType(Veterinary *veterinary){
	utlLb_getOwnersHarcodedData1(veterinary->owners, &veterinary->ownerId);
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);
	utilLb_showPetsByType(veterinary->pets, veterinary->breeds, PETS_TOP, BREEDS_TOP, 1);
}
//pregunta 14 y 15
//Ordeno por cant mascotas si esta cantidades son iguales se ordena alfabeticamente por nombre en forma ascendente
void entTst_sortOwnerByPetsNumberAndOwnerName(Veterinary *veterinary){
	int mode = 1; //1=asc 0=dsc
	utlLb_getOwnersHarcodedData1(veterinary->owners, &veterinary->ownerId);
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);

	printf("--->BEFORE------->:\n");
	utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
	utilLb_sortOwnerByNumberOfPetsAndOwnerName(veterinary->owners, veterinary->pets, OWNER_TOP, PETS_TOP, 1);
	printf("--->AFTER------->:\n");
	utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
}

void entTst_calculateAndShowAllInfo(Veterinary *veterinary){
	utlLb_getOwnersHarcodedData1(veterinary->owners, &veterinary->ownerId);
	utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
	utlLb_getPetsHarcodedData1(veterinary->pets, &veterinary->petId);

	utilLb_calculateAndShowPetsAgeAverage(veterinary->pets, PETS_TOP);
	utilLb_calculatePetsAgeAverageByType(veterinary->pets, PETS_TOP);
	utilLb_calculatePercentageOwnerByGender(veterinary->owners, OWNER_TOP);

	utilLb_showCustomerWithPetsSameGender(veterinary->owners, veterinary->pets,
	OWNER_TOP, PETS_TOP);
}
