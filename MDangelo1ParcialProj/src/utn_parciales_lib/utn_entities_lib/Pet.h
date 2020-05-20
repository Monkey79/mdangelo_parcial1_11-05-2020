/*
 * Pet.h
 *  Created on: 11 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_PET_H_
#define UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_PET_H_

#include "DataType.h"

void ptLib_initPets(Pet pets[], int petTop);

int ptLib_createPet(Pet pets[], Pet pet, int petTop);
int ptLib_deletePet(Pet pets[], int petId, int petTop);
void ptLib_deletePetsByCustomerId(Pet pets[], int customerId, int petTop);
int ptLib_updatePet(Pet pets[], Pet pet, int petTop);

int ptLib_checkPetIdExists(Pet pets[],int petTop,int petId);
int ptLib_getNumberOfPetsByCustomerId(Pet pets[], int petTop, int customerId);
void ptLib_showPets(Pet pets[], int petTop);
void ptLib_getTypeDescription(char typeDescription[], int typeInt);
void ptLib_checkPetsAreSameGenderByCustomerId(Pet pets[], int petTop, int customerId, int *pSameGender);

#endif /* UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_PET_H_ */
