/*
 ============================================================================
 Name        : MDangeloParc1LaboV2.c
 Author      : mdangelo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn_mdangelo_test/EntitiesTest.h"
#include "utn_mdangelo_business/VeterinaryBusiness.h"

#define TEST_MODE 1

int main(void) {
	Veterinary veterinary;

	vtBsns_initializeAllVeterinary(&veterinary,TEST_MODE);

	if(!TEST_MODE)
		vtnBsn_startVeterinary(&veterinary);
	else{
		//entTst_petCreationTest(&veterinary);
		//entTst_updateABreedTest(&veterinary);
		//entTst_deleteAPetTest(&veterinary);
		//entTst_updateAPetTest(&veterinary);
		//entTst_updateOwnerTest(&veterinary);
		//entTst_createOwnerTest(&veterinary);
		//entTst_deleteOwner(&veterinary);

		//entTst_sortPetsByTypeAndShowAll(&veterinary);
		//entTst_showOwnerWithPets(&veterinary);
		//entTst_showPetsMoreThan3YearsAndHisOwner(&veterinary);
		//entTst_showPetsByType(&veterinary);
		//entTst_sortOwnerByPetsNumberAndOwnerName(&veterinary);
		//entTst_calculateAndShowAllInfo(&veterinary);
	}
	printf("============END==================\n");
	return EXIT_SUCCESS;
}
