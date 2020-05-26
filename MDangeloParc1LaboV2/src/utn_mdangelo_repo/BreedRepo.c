/*
 * BreedRepo.c
 *  Created on: 20 may. 2020
 *  Author: mdangelo
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "BreedRepo.h"

int _getBreedEmptyIndex(Breed breeds[], int breedTop);
int _getBreedIndexById(Breed breeds[],int breedId, int breedTop);

void breedRp_initializeBreeds(Breed breeds[], int breedTop){
	for (int i = 0; i < breedTop; i++) {
		breeds[i].id = -1;
		breeds[i].empty = TRUE;
	}
}

int breedRp_addBreed(Breed breeds[], int breedTop, Breed breed){
	int success = TRUE;
	int i = _getBreedEmptyIndex(breeds, breedTop);
	if(i>=0){
		breeds[i] = breed;
		breeds[i].empty = FALSE;
	}else{
		printf(NO_EMPTY_SPACE);
		success = FALSE;
	}
	return success;
}
int breedRp_updateBreed(Breed breeds[], int breedTop, Breed breed){
	int success = TRUE;
	int i = _getBreedIndexById(breeds, breed.id, breedTop);
	if(i>=0){
		//breed.id = breeds[i].id;
		breeds[i] = breed;
		breeds[i].empty = FALSE;
	}else{
		printf(NO_ENTITY_FOUND);
		success = FALSE;
	}
	return success;
}
int breedRp_deleteBreedById(Breed breeds[], int breedTop, int ownerId){
	int success = TRUE;
	int i = _getBreedIndexById(breeds, ownerId, breedTop);
	if(i>=0){
		breeds[i].id = -1;
		breeds[i].empty = TRUE;
	}else{
		printf(NO_ENTITY_FOUND, ownerId);
		success = FALSE;
	}
	return success;
}
/******Private functions************/
int _getBreedEmptyIndex(Breed breeds[], int breedTop){
	int i;
	for(i=0;i<breedTop && !breeds[i].empty;i++);
	return i;
}

int _getBreedIndexById(Breed breeds[],int breedId, int breedTop){
	int i;
	for(i=0;i<breedTop && breeds[i].id!=breedId;i++);
	return i;
}
