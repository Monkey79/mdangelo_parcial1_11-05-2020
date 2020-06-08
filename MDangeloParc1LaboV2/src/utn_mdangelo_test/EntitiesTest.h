/*
 * PetTest.c
 *  Created on: 6 jun. 2020
 *  Author: mdagelo
 */

#ifndef UTN_MDANGELO_TEST_ENTITIESTEST_H_
#define UTN_MDANGELO_TEST_ENTITIESTEST_H_

#include "../utn_mdangelo_entities/MainEntities.h"

int entTst_petCreationTest(Veterinary * pVet);
int entTst_updateABreedTest(Veterinary *veterinary);
int entTst_deleteAPetTest(Veterinary *veterinary);
int entTst_updateAPetTest(Veterinary *veterinary);
int entTst_updateOwnerTest(Veterinary *veterinary);
int entTst_createOwnerTest(Veterinary *veterinary);
int entTst_deleteOwner(Veterinary *veterinary);

void entTst_sortPetsByTypeAndShowAll(Veterinary *veterinary);
void entTst_showOwnerWithPets(Veterinary *veterinary);
void entTst_showPetsMoreThan3YearsAndHisOwner(Veterinary *veterinary);
void entTst_showPetsByType(Veterinary *veterinary);
void entTst_sortOwnerByPetsNumberAndOwnerName(Veterinary *veterinary);
void entTst_calculateAndShowAllInfo(Veterinary *veterinary);

#endif /* UTN_MDANGELO_TEST_ENTITIESTEST_H_ */
