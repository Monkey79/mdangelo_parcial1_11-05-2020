/*
 * BreedService.c
 *  Created on: 21 may. 2020
 *  Author: mdangelo
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "BreedService.h"

#define BREED_MSSG_1 "Atencion: De las siguientes razas seleccione una\n"

//******Private Functions***********
int _checkIsValidBreedId(Breed breeds[],int breedId);
void _showAllBreeds(Breed breeds[], int breedTop);
void _showBreedHeaderDataGrid(void);
//***********************************

void breedSvc_initializeAllBreeds(Breed breeds[], int breedTop){
	breedRp_initializeBreeds(breeds, breedTop);
}

void breedSvc_getValidBreedId(Breed breeeds[], int *breedId, int breedTop){
	printf(BREED_MSSG_1);
	do{
		_showAllBreeds(breeeds, breedTop);
		__fpurge(stdin);
		scanf("%d",breedId);
	}while(!_checkIsValidBreedId(breeeds,*breedId));
}

void breedSvc_getBreedByPetId(Breed breeds[],int breedTop, int petBreedId, Breed *breeed){
	for(int i=0;i<breedTop;i++){
		if(!breeds[i].empty && breeds[i].id == petBreedId){
			*breeed = breeds[i];
		}
	}
}

int breedSvc_updateBreed(Breed breeds[], int breedTop){
	int breedId;
	int success;
	Breed breedUpd;

	breedSvc_getValidBreedId(breeds,&breedId, breedTop);

	printf("Ingrese el nuevo nombre de la raza: ");
	__fpurge(stdin);
	fgets(breedUpd.breedName, 50, stdin);
	utilLb_cleanStrValue(breedUpd.breedName);
	printf("Ingrese el nuevo pais de origen de la raza: ");
	__fpurge(stdin);
	fgets(breedUpd.breedCountry, 50, stdin);
	utilLb_cleanStrValue(breedUpd.breedCountry);

	breedUpd.id = breedId;
	success = breedRp_updateBreed(breeds, breedTop, breedUpd);
	if(!success) breedId = -1;
	return breedId;
}

void breedSvc_showAllBreeds(Breed breeds[],int breedTop){
	_showAllBreeds(breeds, breedTop);
}

//******Private Functions***********
int _checkIsValidBreedId(Breed breeds[],int breedId){
	int i;
	for(i=0;i<BREEDS_TOP && (breeds[i].id != breedId || breeds[i].empty);i++);
	return (breeds[i].id == breedId);
}

void _showAllBreeds(Breed breeds[], int breedTop){
	_showBreedHeaderDataGrid();
	for(int i=0;i<breedTop;i++){
		if(!breeds[i].empty)
		printf("%d \t%20s \t%22s \n",breeds[i].id,breeds[i].breedName,breeds[i].breedCountry);
	}
}

void _showBreedHeaderDataGrid(void){
	printf("Breed_Id\t");
	printf("Breed_Name\t");
	printf("Breed_Country\t\n");
}
