/*
 * PetService.h
 *  Created on: 20 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_MDANGELO_SERVICE_PETSERVICE_H_
#define UTN_MDANGELO_SERVICE_PETSERVICE_H_

#include "../utn_mdangelo_utils/Utils.h"
#include "../utn_mdangelo_repo/PetRepo.h"

void petSvc_initializeAllPets(Pet pets[], int petTop);
int petSv_createPet(Pet pets[],int breedId,int ownerId, int *petId);
int petSv_updatePet(Pet pets[],int petUpdId,int breedUpdId,int petTop);
int petSv_deletePet(Pet pets[],int petIdDelt,int petTop);
int petSv_deletePetByOwnerId(Pet pets[],int ownerId, int petTop);

void petSv_getValidPeetId(Pet pets[], int *peetId, int petTop);
int petSv_checkValidPetId(Pet pets[],int petTop, int petId);
int petSv_getNumberOfPetsByOwnerId(Pet pets[],int petTop, int ownerId);
void petSv_checkPetsAreSameGenderByOwnerId(Pet pets[], int petTop, int ownerId, int *pSameGender);
void petSv_getLength(Pet pets[],int *pPetLen, int petTop);
void petSv_getValidPetType(int *pPetType);
#endif /* UTN_MDANGELO_SERVICE_PETSERVICE_H_ */
