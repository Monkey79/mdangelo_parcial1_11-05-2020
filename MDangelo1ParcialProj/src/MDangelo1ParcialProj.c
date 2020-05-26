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
#define RACES_TOP 6

int main(void) {
	int customerId=0; //AI
	int petId=0; 	  //AI
	int raceId=0;

	Customer customers[CUSTOMER_TOP];
	Pet pets[PETS_TOP];
	Race races[RACES_TOP];

	/**Usr input***/
	mngLib_initializeAll(customers, pets,races,CUSTOMER_TOP,PETS_TOP, RACES_TOP);

	/****CRUD*****/
	//tstLb_test1createPet(customers,pets,races, &customerId, &petId, &raceId, CUSTOMER_TOP, PETS_TOP, RACES_TOP);  //OK
	//tstLb_test2deletePet(pets,races,&petId,&raceId,PETS_TOP,RACES_TOP); //OK
	//tstLb_test3UpdatePet(pets,races,&petId,&raceId,PETS_TOP,RACES_TOP); //OK

	//tstLb_test4CreateCustomer(customers,&customerId,CUSTOMER_TOP);  //OK
	//tstLb_test4AUpdateCustomer(customers,&customerId,CUSTOMER_TOP); //OK
	//tstLb_test4BUpdateRace(races,RACES_TOP, &raceId); //OK
	//tstLb_test5DeleteCustomerAndHisPets(customers,pets,races,&customerId,&petId,&raceId,CUSTOMER_TOP, PETS_TOP,RACES_TOP); //Ok

	/****LIST*****/
	//tstLb_test6AListCustomerAndHisPets(customers,pets,races, &customerId, &petId,&raceId, CUSTOMER_TOP, PETS_TOP,RACES_TOP); //OK
	//tstLb_test6ListCustomerPetsMoreThan3Years(customers,pets,races, &customerId, &petId,&raceId, CUSTOMER_TOP, PETS_TOP,RACES_TOP); //OK
	//tstLb_test7ListPetsByType(pets,races,PETS_TOP,RACES_TOP, 1,&petId, &raceId); //OK

	/****ORDER-SORT*****/
	tstLb_test8OrderPetsByTypeAscAndShowAll(customers,pets,races,&customerId,&petId,&raceId, CUSTOMER_TOP, PETS_TOP,RACES_TOP); //Ok
	//tstLb_test9OrderCustomerByNumberOfPetsAndShowAll(customers,pets,races,&customerId, &petId,&raceId, CUSTOMER_TOP,PETS_TOP,RACES_TOP); //Ok


	/****AVERAGE*****/
	//tstLib_test10PetsAverageAgeAndShow(pets, PETS_TOP,&petId); //OK
	//tstLib_test11CustomerMaleFemaleAverageAndShow(customers,&customerId,CUSTOMER_TOP); //OK
	//tstLib_test12ListCustomerWithPetsSameGender(customers,pets,&customerId,&petId,CUSTOMER_TOP, PETS_TOP); //OK

	printf("==END====");
	return EXIT_SUCCESS;
}
