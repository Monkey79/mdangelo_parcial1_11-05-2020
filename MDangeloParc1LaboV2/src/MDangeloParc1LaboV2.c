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
#include "utn_mdangelo_business/VeterinaryBusiness.h"

int main(void) {
	Veterinary veterinary;

	vtBsns_initializeAllVeterinary(&veterinary);

	/*******CRUD*******/
	//vtnBsns_createAPet(&veterinary);
	//vtnBsns_updateABreed(&veterinary);
	//vtnBsns_deleteAPet(&veterinary);
	//vtnBsns_updateAPet(&veterinary);
	//vtnBsns_updateOwner(&veterinary);
	//vtnBsns_createOwner(&veterinary);
	//vtnBsns_deleteOwner(&veterinary);

	//vtnBsn_sortPetsByTypeAndShowAll(&veterinary);
	//vtnBsn_showOwnerWithPets(&veterinary);
	//vtnBsn_showPetsMoreThan3YearsAndHisOwner(&veterinary);
	//vtnBsn_showPetsByType(&veterinary);
	//vtnBsn_sortOwnerByPetsNumberAndOwnerName(&veterinary);
	//vtnBsn_calculateAndShowAllInfo(&veterinary);

	printf("============END==================\n");
	return EXIT_SUCCESS;
}
