/*
 * Pet.c
 *  Created on: 20 may. 2020
 *  Author: mdangelo
 */

#include "PetRepo.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

//************Private functions********************
int _getPetEmptyIndex(Pet pets[],int petsTop);
int _getPetIndexById(Pet pets[],int petId,int petsTop);
//***************************************************

void petRp_initializePets(Pet pets[], int petTop) {
	for (int i = 0; i < petTop; i++) {
		pets[i].id = -1;
		pets[i].ownerId = -1;
		pets[i].breedId = -1;
		pets[i].empty = TRUE;
	}
}

int petRp_createPet(Pet pets[], Pet pet, int petTop) {
	int success=TRUE;
	int i = _getPetEmptyIndex(pets, petTop);
	if(i>=0){
		pets[i] =  pet;
		pets[i].empty = FALSE;
	}else{
		printf(NO_EMPTY_SPACE);
		success = FALSE;
	}
	return success;
}

int ptLib_updatePet(Pet pets[], Pet pet, int petTop){
	int success = TRUE;
	int i = _getPetIndexById(pets, pet.id, petTop);
	if(i>=0){
		pet.breedId = (pet.breedId==0)?pets[i].breedId:pet.breedId;
		pet.ownerId = pets[i].ownerId;
		pets[i] = pet;
		pets[i].empty = FALSE;
	}else{
		printf(NO_ENTITY_FOUND, pet.id);
		success = FALSE;
	}
	return success;
}

int petRp_deletePetById(Pet pets[], int petId, int petTop){
	int success = TRUE;
	int i = _getPetIndexById(pets, petId, petTop);
	if(i>=0){
		pets[i].id=-1;
		pets[i].ownerId = -1;
		pets[i].breedId = -1;
		pets[i].empty = TRUE;
	}else{
		printf(NO_ENTITY_FOUND, petId);
		success = FALSE;
	}
	return success;
}

int ptLib_deletePetsByOwnerId(Pet pets[], int ownerId, int petTop){
	int match=FALSE; //si ese dueño tiene o no mascotas
	for(int i=0;i<petTop;i++){
		if(!pets[i].empty && pets[i].ownerId==ownerId){
			pets[i].ownerId = -1;
			pets[i].empty = TRUE;
			pets[i].breedId = -1;
			match = TRUE;
		}
	}
	return match;
}


//**************Private functions********************
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


