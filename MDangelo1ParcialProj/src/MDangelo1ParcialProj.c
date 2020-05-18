/*
 ============================================================================
 Name        : MDangelo1ParcialProj.c
 Author      : mdangelo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "utn_parciales_lib/CustomersPetsManager.h"
#include "utn_parciales_lib/utn_helpers_lib/CustomersPetsDataSets.h"
#include "utn_parciales_lib/utn_test_lib/CustomerPetsTest.h"

#define CUSTOMER_TOP 5 	//10
#define PETS_TOP 11 	//20

int main(void) {
	int customerId=0; //AI
	int petId=0; 	  //AI

	Customer customers[CUSTOMER_TOP];
	Pet pets[PETS_TOP];

	/**Usr input***/
	mngLib_initializeAll(customers, pets,CUSTOMER_TOP,PETS_TOP);

	/****CRUD*****/
	//tstLb_test1createPet(customers,pets, &customerId, &petId, CUSTOMER_TOP, PETS_TOP);
	//tstLb_test2deletePet(pets,&petId,PETS_TOP);
	//tstLb_test3UpdatePet(pets,&petId,PETS_TOP);
	//tstLb_test4CreateCustomer(customers,&customerId,CUSTOMER_TOP);
	//tstLb_test5DeleteCustomerAndHisPets(customers,pets,&customerId,&petId,CUSTOMER_TOP, PETS_TOP);

	/****LIST*****/
	//tstLb_test6ListCustomerPetsMoreThan3Years(customers,pets, &customerId, &petId, CUSTOMER_TOP, PETS_TOP);
	//tstLb_test7ListPetsByType(pets,PETS_TOP, 1,&petId);

	/****ORDER*****/
	//tstLb_test8OrderPetsByTypeAscAndShowAll(customers,pets,&customerId, &petId, CUSTOMER_TOP, PETS_TOP);
	//tstLb_test9OrderCustomerByNumberOfPetsAndShowAll(customers,pets,&customerId, &petId, CUSTOMER_TOP,PETS_TOP);

	/****AVERAGE*****/
	//tstLib_test10PetsAverageAgeAndShow(pets, PETS_TOP,&petId);
	//tstLib_test11CustomerMaleFemaleAverageAndShow(customers,&customerId,CUSTOMER_TOP);

	printf("==END====");
	return EXIT_SUCCESS;
}
