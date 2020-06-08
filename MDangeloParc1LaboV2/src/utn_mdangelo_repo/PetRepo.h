/*
 * Pet.h
 *
 *  Created on: 20 may. 2020
 *      Author: monkey
 */

#ifndef UTN_MDANGELO_REPO_PETREPO_H_
#define UTN_MDANGELO_REPO_PETREPO_H_

#include "../utn_mdangelo_entities/MainEntities.h"

void petRp_initializePets(Pet pets[],int petTop);
int petRp_createPet(Pet pets[], Pet pet, int petTop);
int ptLib_updatePet(Pet pets[], Pet pet, int petTop);
int petRp_deletePetById(Pet pets[], int petId, int petTop);
int ptLib_deletePetsByOwnerId(Pet pets[], int customerId, int petTop);


#endif /* UTN_MDANGELO_REPO_PETREPO_H_ */
