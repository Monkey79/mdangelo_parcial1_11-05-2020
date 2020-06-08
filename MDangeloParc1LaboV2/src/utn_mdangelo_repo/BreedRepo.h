/*
 * BreedRepo.h
 *  Created on: 20 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_MDANGELO_REPO_BREEDREPO_H_
#define UTN_MDANGELO_REPO_BREEDREPO_H_

#include "../utn_mdangelo_entities/MainEntities.h"

void breedRp_initializeBreeds(Breed breeds[], int breedTop);
int breedRp_addBreed(Breed breeds[], int breedTop, Breed breed);
int breedRp_updateBreed(Breed breeds[], int breedTop, Breed breed);
int breedRp_deleteBreedById(Breed breeds[], int breedTop, int ownerId);


#endif /* UTN_MDANGELO_REPO_BREEDREPO_H_ */
