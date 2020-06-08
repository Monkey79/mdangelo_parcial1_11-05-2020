/*
 * VeterinaryBusiness.c
 *  Created on: 21 may. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <ctype.h>

#include "../utn_mdangelo_commons/CommonsValue.h"
#include "VeterinaryBusiness.h"

#define END 0
#define CREATE_PET	1
#define DELETE_PET	2
#define UPDATE_PET	3
#define CREATE_OWNER 4
#define DELETE_OWNER 5
#define UPDATE_OWNER 6
#define UPDATE_BREED 7

#define SHOW_OWNER_WITH_PETS 8
#define SHOW_PETS_MORE_3YEARS 9
#define SHOW_PETS_BY_TYPE 10
#define SHOW_OWNER_PETS_GENDER 11

#define SORT_PETS_BY_TYPE_SHOW 12
#define CALC_INFO_AND_SHOW 13
#define SORT_PETS_BY_PETS_NUM_ALPHA 14

void _startOpertaionByUserSelection(int userSelection, Veterinary *pVeterinary);

void vtBsns_initializeAllVeterinary(Veterinary *veterinary, int testMode){
	veterinary->breedId = 0;
	veterinary->ownerId = 0;
	veterinary->petId = 0;

	/***Inicializo***/
	breedSvc_initializeAllBreeds(veterinary->breeds, BREEDS_TOP);
	ownerSvc_initializeAllOwners(veterinary->owners, OWNER_TOP);
	petSvc_initializeAllPets(veterinary->pets, PETS_TOP);
	/**Harcodeo-Razas**/
	if(!testMode)utlLb_getBreedHarcodedData1(veterinary->breeds, &veterinary->breedId);
}

void vtnBsn_startVeterinary(Veterinary *veterinary) {
	int userSelection = 0;
	utilLb_createMenuAndCallUserSelectionChecker(&userSelection, veterinary, _startOpertaionByUserSelection);
}

/******CRUD Operations******/
void vtnBsns_createAPet(Veterinary *veterinary) {
	int ownerId;
	int breedId;
	int status;

	int ownerLen = 0;
	ownerSvc_getLength(veterinary->owners,&ownerLen, OWNER_TOP);

	if (ownerLen>=1) {
		printf("--------------------Crear Mascota-------------------------\n");
		ownerSvc_getValidOwnerId(veterinary->owners, &ownerId, OWNER_TOP); //pido id de dueño existente
		breedSvc_getValidBreedId(veterinary->breeds, &breedId, BREEDS_TOP); //pido id de raza existente

		status = petSv_createPet(veterinary->pets, breedId, ownerId, &veterinary->petId);
		if (status) {
			printf(CREATION_PET_SUCCESS_MSSG, veterinary->petId);
			utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
		} else {
			printf(CREATION_ERROR_MSSG);
		}
	}else{
		printf("--Por lo menos debe existir un dueño y una raza de mascota para crear la misma---\n");
	}
}

void vtnBsns_updateABreed(Veterinary *veterinary){
	int breedId;

	printf("--------------------Actualizar Raza-------------------------\n");
	breedId = breedSvc_updateBreed(veterinary->breeds, BREEDS_TOP);
	if (breedId) {
		printf(UPDATE_BREED_SUCCESS_MSSG, breedId);
		breedSvc_showAllBreeds(veterinary->breeds, BREEDS_TOP);
	} else {
		printf(CREATION_ERROR_MSSG);
	}
}

void vtnBsns_deletePet(Veterinary *veterinary){
	int petIdDelet;
	int status = SUCCESS;
	int petLen = 0;
	petSv_getLength(veterinary->pets,&petLen,PETS_TOP);

	printf("--------------------Eliminar Mascota-------------------------\n");
	if(petLen>=1){
		/*****Join with Breed******/
		do {
			printf("--De las siguiente mascotas (y sus razas) selecciones un id valido--\n");
			utilLb_showAllPetsAndTheirBreeds(veterinary->pets, veterinary->breeds,BREEDS_TOP, PETS_TOP);
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
	}else{
		printf("--No hay mascotas para eliminar  (cree una mascota primero)--\n");
	}
}

void vtnBsns_updatePet(Veterinary *veterinary){
	int status = FALSE;
	int breedUpdId = 0;
	int petUpdId = 0;
	char updateBreed;
	int petLen = 0;
	petSv_getLength(veterinary->pets,&petLen,PETS_TOP);

	printf("--------------------Actualizar Mascota (y su raza)-------------------------\n");
	if(petLen>=1){
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
	}else{
		printf("--No hay mascotas para actualizar (cree una mascota primero)--\n");
	}
}

void vtnBsns_updateOwner(Veterinary *veterinary){
	int ownerUpdId = 0;
	int status = SUCCESS;
	int ownerLen=0;
	ownerSvc_getLength(veterinary->owners,&ownerLen,OWNER_TOP);

	printf("--------------------Actualizar Dueño-------------------------\n");
	if(ownerLen>=1){
		ownerSvc_getValidOwnerId(veterinary->owners, &ownerUpdId, OWNER_TOP);
		status = ownerSvc_updateOwner(veterinary->owners, OWNER_TOP, ownerUpdId);
		if (status) {
			printf(UPDATE_OWNER_SUCCESS_MSSG);
			utilLb_showOwnersOnly(*veterinary, OWNER_TOP);
		} else {
			printf(UPDATE_ERROR_MSSG);
			status = ERROR;
		}
	}else{
		printf("--No hay dueños para actualizar (primero cree un dueño)--\n");
	}
}

void vtnBsns_createOwner(Veterinary *veterinary){
	printf("--------------------Creando Dueño-------------------------\n");
	int status = ownerSvc_createOwner(veterinary->owners, OWNER_TOP, &veterinary->ownerId);
	if (status) {
		printf(CREATE_OWNER_SUCCESS_MSSG, veterinary->ownerId);
		utilLb_showOwnersOnly(*veterinary, OWNER_TOP);
	} else {
		printf(CREATE_ERROR_MSSG);
		status = ERROR;
	}
}

void vtnBsns_deleteOwner(Veterinary *veterinary){
	int ownerDelId;
	int status;
	int ownerLen=0;
	ownerSvc_getLength(veterinary->owners,&ownerLen,OWNER_TOP);

	printf("--------------------Borrando Dueño-------------------------\n");
	if(ownerLen>=1){
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
	}else{
		printf("--No hay dueños para borrar (primero cree un dueño)--\n");
	}
}
/*******************************/
//pregunta 11
void vtnBsn_showOwnerWithPets(Veterinary *veterinary){
	int ownerLen=0;
	ownerSvc_getLength(veterinary->owners,&ownerLen,OWNER_TOP);
	if(ownerLen>=1){
		utilLb_showOwnerThaHavePets(veterinary->owners, veterinary->pets, OWNER_TOP, PETS_TOP);
	}else{
		printf("--No hay dueños (primero cree un dueño)--\n");
	}

}
//pregunta 12
void vtnBsn_showPetsMoreThan3YearsAndHisOwner(Veterinary *veterinary){
	int ownerLen=0;
	ownerSvc_getLength(veterinary->owners,&ownerLen,OWNER_TOP);
	int petLen=0;
	petSv_getLength(veterinary->pets,&petLen, PETS_TOP);
	if(ownerLen>=1 && petLen>=1){
		utilLb_showPethsMoreNYearWithOwner(*veterinary, OWNER_TOP, PETS_TOP, BREEDS_TOP, 3);
	}else{
		printf("--NO hay dueños y/o mascotas (primero cree un dueño y asignele una mascota)--\n");
	}

}

//pregunta 13
void vtnBsn_showPetsByType(Veterinary *veterinary) {
	int ownerLen=0;
	ownerSvc_getLength(veterinary->owners,&ownerLen,OWNER_TOP);
	int petLen=0;
	petSv_getLength(veterinary->pets,&petLen, PETS_TOP);
	int petType=0;
	if(ownerLen>=1 && petLen>=1){
		petSv_getValidPetType(&petType);
		utilLb_showPetsByType(veterinary->pets, veterinary->breeds, PETS_TOP, BREEDS_TOP, petType);
	}else{
		printf("--NO hay dueños y/o mascotas (primero cree un dueño y asignele una mascota)--\n");
	}
}
void vtnBsn_showOwnerWithPetsSameGender(Veterinary *veterinary){
	int ownerLen=0;
	ownerSvc_getLength(veterinary->owners,&ownerLen,OWNER_TOP);
	int petLen=0;
	petSv_getLength(veterinary->pets,&petLen, PETS_TOP);
	int petType=0;
	if(ownerLen>=1 && petLen>=1){
		utilLb_showCustomerWithPetsSameGender(veterinary->owners, veterinary->pets,OWNER_TOP, PETS_TOP);
	}else{
		printf("--NO hay dueños y/o mascotas (primero cree un dueño y asignele una mascota)--\n");
	}
}

//Pregunta 9
void vtnBsn_sortPetsByTypeAndShowAll(Veterinary *veterinary) {
	int ownerLen=0;
	ownerSvc_getLength(veterinary->owners,&ownerLen,OWNER_TOP);
	int petLen=0;
	petSv_getLength(veterinary->pets,&petLen, PETS_TOP);
	if(ownerLen>=1 && petLen>=1){
		printf("----------ANTES---------------\n");
		utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
		utilLb_sortPetsByType(veterinary->pets, PETS_TOP, 1); //1=ASC 0=DSC
		printf("----------DESPUES-------------\n");
		utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
	}else{
		printf("--NO hay dueños ni mascotas (primero cree un dueño y asignele una mascota)--\n");
	}

}

//pregunta 14 y 15
//Ordeno por cant mascotas si esta cantidades son iguales se ordena alfabeticamente por nombre en forma ascendente
void vtnBsn_sortOwnerByPetsNumberAndOwnerName(Veterinary *veterinary){
	int mode = 1; //1=asc 0=dsc
	int ownerLen=0;
	ownerSvc_getLength(veterinary->owners,&ownerLen,OWNER_TOP);
	int petLen=0;
	petSv_getLength(veterinary->pets,&petLen, PETS_TOP);
	if(ownerLen>=1 && petLen>=1){
		printf("--->BEFORE------->:\n");
		utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
		utilLb_sortOwnerByNumberOfPetsAndOwnerName(veterinary->owners, veterinary->pets, OWNER_TOP, PETS_TOP, mode);
		printf("--->AFTER------->:\n");
		utilLb_showOwnersAndTheirPetsWithBreeds(*veterinary);
	}else{
		printf("--NO hay dueños y/o mascotas (primero cree un dueño y asignele una mascota)--\n");
	}
}

void vtnBsn_calculateAndShowAllInfo(Veterinary *veterinary) {
	int ownerLen=0;
	ownerSvc_getLength(veterinary->owners,&ownerLen,OWNER_TOP);
	int petLen=0;
	petSv_getLength(veterinary->pets,&petLen, PETS_TOP);
	if(ownerLen>=1 && petLen>=1){
		utilLb_calculateAndShowPetsAgeAverage(veterinary->pets, PETS_TOP);
		utilLb_calculatePetsAgeAverageByType(veterinary->pets, PETS_TOP);
		utilLb_calculatePercentageOwnerByGender(veterinary->owners, OWNER_TOP);
	}else{
		printf("--NO hay dueños y/o mascotas (primero cree un dueño y asignele una mascota)--\n");
	}
}
//************Private Functions********************
void _startOpertaionByUserSelection(int userSelection, Veterinary *pVeterinary) {
	printf("--User selection %d--\n", userSelection);
	switch (userSelection) {
		case CREATE_PET:
			vtnBsns_createAPet(pVeterinary);
			break;
		case DELETE_PET:
			vtnBsns_deletePet(pVeterinary);
			break;
		case UPDATE_PET:
			vtnBsns_updatePet(pVeterinary);
			break;
		case CREATE_OWNER:
			vtnBsns_createOwner(pVeterinary);
			break;
		case DELETE_OWNER:
			vtnBsns_deleteOwner(pVeterinary);
			break;
		case UPDATE_OWNER:
			vtnBsns_updateOwner(pVeterinary);
			break;
		case UPDATE_BREED:
			vtnBsns_updateABreed(pVeterinary);
			break;
		case SHOW_OWNER_WITH_PETS:
			vtnBsn_showOwnerWithPets(pVeterinary);
			break;
		case SHOW_PETS_MORE_3YEARS:
			vtnBsn_showPetsMoreThan3YearsAndHisOwner(pVeterinary);
			break;
		case SHOW_PETS_BY_TYPE:
			vtnBsn_showPetsByType(pVeterinary);
			break;
		case SHOW_OWNER_PETS_GENDER:
			vtnBsn_showOwnerWithPetsSameGender(pVeterinary);
			break;
		case SORT_PETS_BY_TYPE_SHOW:
			vtnBsn_sortPetsByTypeAndShowAll(pVeterinary);
			break;
		case CALC_INFO_AND_SHOW:
			vtnBsn_calculateAndShowAllInfo(pVeterinary);
			break;
		case SORT_PETS_BY_PETS_NUM_ALPHA:
			vtnBsn_sortOwnerByPetsNumberAndOwnerName(pVeterinary);
			break;
		case END:
			printf("============END==================\n");
			exit(EXIT_SUCCESS);
			break;

	}
}

