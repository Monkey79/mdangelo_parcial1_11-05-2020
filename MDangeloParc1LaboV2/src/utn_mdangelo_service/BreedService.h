/*
 * BreedService.h
 * Created on: 21 may. 2020
 * Author: mdangelo
 */

#ifndef UTN_MDANGELO_SERVICE_BREEDSERVICE_H_
#define UTN_MDANGELO_SERVICE_BREEDSERVICE_H_

#include "../utn_mdangelo_utils/Utils.h"
#include "../utn_mdangelo_repo/BreedRepo.h"

void breedSvc_initializeAllBreeds(Breed breeds[], int breedTop);
void breedSvc_getValidBreedId(Breed breeeds[], int *breedId, int breedTop);
void breedSvc_getBreedById(Breed breeds[], int breedId, Breed *breed);
void breedSvc_getBreedByPetId(Breed breeds[],int breedTop, int petBreedId, Breed *breeed);

int breedSvc_updateBreed(Breed breeds[], int breedTop);
#endif /* UTN_MDANGELO_SERVICE_BREEDSERVICE_H_ */
