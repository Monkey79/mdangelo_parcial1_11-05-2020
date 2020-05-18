/*
 * Pet.c
 *  Created on: 11 may. 2020
 *  Author: mdangelo
 */

#include "../utn_entities_lib/Pet.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#define TRUE 1
#define FALSE 0

int _getPetEmptyIndex(Pet pets[],int petsTop);
int _getPetIndexById(Pet pets[],int petId,int petsTop);

void ptLib_initPets(Pet pets[], int petTop){
	for(int i=0;i<petTop;i++){
		pets[i].id = -1;
		pets[i].customerId = -1;
		pets[i].empty = TRUE;
	}
}

int ptLib_createPet(Pet pets[], Pet pet, int petTop) {
	int success = TRUE;
	int i = _getPetEmptyIndex(pets, petTop);
	if(i>=0){
		pets[i] =  pet;
	}else{
		printf("[Attention] No more empty space\n");
		success = FALSE;
	}
	return success;
}

int ptLib_deletePet(Pet pets[], int petId, int petTop){
	int success = TRUE;
	int i = _getPetIndexById(pets, petId, petTop);
	if(i>=0){
		pets[i].id=-1;
		pets[i].customerId = -1;
		pets[i].empty = TRUE;
	}else{
		printf("[Error] There is no pet with this id=%d\n", petId);
		success = FALSE;
	}
	return success;
}

void ptLib_deletePetsByCustomerId(Pet pets[], int customerId, int petTop){
	for(int i=0;i<petTop;i++){
		if(!pets[i].empty && pets[i].customerId==customerId){
			pets[i].customerId = -1;
			pets[i].empty = TRUE;
		}
	}
}

int ptLib_updatePet(Pet pets[], Pet pet, int petTop){
	int success = TRUE;
	int i = _getPetIndexById(pets, pet.id, petTop);
	if(i>=0){
		pet.customerId = pets[i].customerId;
		pets[i] = pet;
	}else{
		printf("[Error] There is no pet with this id=%d\n", pet.id);
		success = FALSE;
	}
	return success;
}

int ptLib_checkPetIdExists(Pet pets[],int petTop,int petId){
	int i;
	for(i=0;i<petTop && pets[i].id!=petId;i++);
	return (pets[i].id==petId);
}
int ptLib_getNumberOfPetsByCustomerId(Pet pets[], int petTop, int customerId){
	int petsNmb = 0;
	for(int i=0;i<petTop;i++){
		if(!pets[i].empty && pets[i].customerId == customerId){
			petsNmb++;
		}
	}
	return petsNmb;
}

void ptLib_showPets(Pet pets[], int petTop){
	printf("ID");
	printf("\t Cliente_Id");
	printf("\t Nombre");
	printf("\t\t\t Tipo");
	printf("\t\t Raza");
	printf("\t\t Edad");
	printf("\t Peso");
	printf("\t Sexo\n");

	char typeAux[8];
	for(int i=0;i<petTop;i++){
		if(!pets[i].empty){
			ptLib_getTypeDescription(typeAux,pets[i].type);
			printf("%d\t\t %d\t %8s\t %11s\t %12s\t\t %d\t %.2f\t %c\n",pets[i].id,
															pets[i].customerId,
															pets[i].name,
															typeAux,
															pets[i].race,
															pets[i].age,
															pets[i].weight,
															pets[i].gender);
			typeAux[0]='\0';
		}
	}
}

void ptLib_showPetsIds(Pet pets[], int petTop){
	printf("\nMascot_ID");
	printf("\tMascot_Nombre\n");
	for(int i=0;i<petTop && !pets[i].empty;i++){
		printf("%d \t%10s \n",pets[i].id,pets[i].name);
	}
}

void ptLib_getTypeDescription(char typeDescription[], int typeInt){
	char descpAux[8];
	switch (typeInt) {
		case 1:
			strcpy(descpAux,"1=Gato\0");
			break;
		case 2:
			strcpy(descpAux,"2=Perro\0");
			break;
		case 3:
			strcpy(descpAux,"3=Raro\0");
			break;
		default:
			break;
	}
	strcpy(typeDescription, descpAux);
}

//**************Private********************
int _getPetEmptyIndex(Pet pets[],int petsTop){
	int i;
	for(i=0;i<petsTop && !pets[i].empty;i++);
	return i;
}
int _getPetIndexById(Pet pets[],int petId,int petsTop){
	int i;
	for(i=0;i<petsTop && pets[i].id!=petId;i++);
	return i;
}

