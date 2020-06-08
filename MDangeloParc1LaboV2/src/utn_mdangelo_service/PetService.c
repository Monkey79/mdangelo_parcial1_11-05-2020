/*
 * PetService.c
 *  Created on: 20 may. 2020
 *  Author: mdangelo
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "PetService.h"

#define PET_MSSG_1 "Atencion: De las siguientes mascotas seleccione una\n"

//*********Private Functions*******************

//*********************************************

void petSvc_initializeAllPets(Pet pets[], int petTop) {
	petRp_initializePets(pets, petTop);
}

int petSv_createPet(Pet pets[], int breedId, int ownerId, int *petId) {
	int status;
	Pet petCreate;

	printf("Ingrese nombre de la mascota:");
	__fpurge(stdin);
	fgets(petCreate.name, 50, stdin);
	utilLb_cleanStrValue(petCreate.name);

	do {
		printf("Ingrese el tipo de mascota [1=gato 2=perro 3=raro]");
		scanf("%d", &petCreate.type);
	} while (petCreate.type != 1 && petCreate.type != 2 && petCreate.type != 3);

	//muestro los ids de las razas diponibles
	//rcLb_getRaceId(races, raceTop, &petCreate.raceId);
	do {
		printf("Ingrese una edad valida para la mascota ");
		__fpurge(stdin);
		scanf("%d", &petCreate.age);
	} while (petCreate.age <= 0);
	do {
		printf("Ingrese un peso valido para la mascota ");
		__fpurge(stdin);
		scanf("%f", &petCreate.weight);
	} while (petCreate.weight <= 0.00);
	do {
		printf("Ingrese sexo de la mascota [M | F]");
		__fpurge(stdin);
		scanf("%c", &petCreate.gender);
		petCreate.gender = toupper(petCreate.gender);
	} while (petCreate.gender != 'M' && petCreate.gender != 'F');
	petCreate.id = ++(*petId);
	petCreate.ownerId = ownerId;
	petCreate.breedId = breedId;
	return petRp_createPet(pets, petCreate, PETS_TOP);

}
int petSv_updatePet(Pet pets[], int petUpdId, int breedUpdId, int petTop) {
	Pet petUpdate;

	printf("Ingrese nuevo nombre de la mascota:");
	__fpurge(stdin);
	fgets(petUpdate.name, 50, stdin);
	utilLb_cleanStrValue(petUpdate.name);

	do {
		printf("Ingrese  el tipo nuevo de mascota [1=gato 2=perro 3=raro]");
		scanf("%d", &petUpdate.type);
	} while (petUpdate.type != 1 && petUpdate.type != 2 && petUpdate.type != 3);

	do {
		printf("Ingrese una nueva edad valida para la mascota ");
		__fpurge(stdin);
		scanf("%d", &petUpdate.age);
	} while (petUpdate.age <= 0);
	do {
		printf("Ingrese un nuevo peso valido para la mascota ");
		__fpurge(stdin);
		scanf("%f", &petUpdate.weight);
	} while (petUpdate.weight <= 0.00);
	do {
		printf("Ingrese nuevo sexo de la mascota [M | F]");
		__fpurge(stdin);
		scanf("%c", &petUpdate.gender);
		petUpdate.gender = toupper(petUpdate.gender);
	} while (petUpdate.gender != 'M' && petUpdate.gender != 'F');

	petUpdate.id = petUpdId;
	petUpdate.breedId = breedUpdId;
	return ptLib_updatePet(pets, petUpdate, PETS_TOP);
}

int petSv_deletePet(Pet pets[], int petIdDelt, int petTop) {
	return petRp_deletePetById(pets, petIdDelt, petTop);
}

int petSv_deletePetByOwnerId(Pet pets[], int ownerId, int petTop) {
	return ptLib_deletePetsByOwnerId(pets, ownerId, petTop);
}

int petSv_checkValidPetId(Pet pets[], int petTop, int petId) {
	int idMatch = FALSE;
	for (int i = 0; i < petTop && !idMatch; i++) {
		if (!pets[i].empty && pets[i].id == petId)
			idMatch = TRUE;
	}
	return idMatch;
}
int petSv_getNumberOfPetsByOwnerId(Pet pets[], int petTop, int ownerId) {
	int petNum = 0;
	for (int i = 0; i < petTop; i++) {
		if (!pets[i].empty && pets[i].ownerId == ownerId)
			petNum++;
	}
	return petNum;
}

void petSv_checkPetsAreSameGenderByOwnerId(Pet pets[], int petTop, int ownerId, int *pSameGender) {
	int femaleCont = 0;
	int maleCont = 0;
	int totalCont = 0;

	for (int i = 0; i < petTop; i++) {
		if (!pets[i].empty && pets[i].ownerId == ownerId) {
			if (pets[i].gender == 'F' || pets[i].gender == 'f')
				femaleCont++;
			else if (pets[i].gender == 'M' || pets[i].gender == 'm')
				maleCont++;

			totalCont++;
		}
	}
	if ((femaleCont == totalCont && totalCont > 1) || (maleCont == totalCont && totalCont > 1))
		*pSameGender = TRUE;
	else
		*pSameGender = FALSE;
}
void petSv_getLength(Pet pets[],int *pPetLen, int petTop){
	for (int i = 0; i < petTop; i++) {
		if (!pets[i].empty) (*pPetLen)++;
	}
}
void petSv_getValidPetType(int *pPetType){
	do{
		printf("--Ingrese un tipo de mascota valido--[1=gato 2=perro y 3=exotico]--\n");
		scanf("%d",pPetType);
	}while(*pPetType!=1 && *pPetType!=2 && *pPetType!=3);
}
//*********Private Functions*******************

