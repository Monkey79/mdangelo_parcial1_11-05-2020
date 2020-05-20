/*
 * CustomerPetsTest.h
 * Created on: 15 may. 2020
 * Author: mdangelo
 */

#ifndef UTN_PARCIALES_LIB_UTN_TEST_LIB_CUSTOMERPETSTEST_H_
#define UTN_PARCIALES_LIB_UTN_TEST_LIB_CUSTOMERPETSTEST_H_


#include "../utn_entities_lib/DataType.h"
#include "../utn_helpers_lib/Helper.h"
#include "../utn_helpers_lib/CustomersPetsDataSets.h"

/*****CRUD : Customer and Pets*******/
void tstLb_test1createPet(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId, int *pRaceId, int customerTop, int petTop, int raceTop);
void tstLb_test2deletePet(Pet pets[],Race races[],int *pPetId, int *pRaceId,int petTop, int raceTop);
void tstLb_test3UpdatePet(Pet pets[],Race races[],int *pPetId, int *pRaceId,int petTop, int raceTop);
void tstLb_test4CreateCustomer(Customer customers[],int *pCustomerId,int customerTop);
void tstLb_test4AUpdateCustomer(Customer customers[],int *pCustomerId,int customerTop);
void tstLb_test5DeleteCustomerAndHisPets(Customer customers[],Pet pets[],Race races[],int *pCustomerId,int *pPetId,int *pRaceId, int customerTop, int petTop,int raceTop);

/*****List : Customer and Pets*******/
void tstLb_test6AListCustomerAndHisPets(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId,int *pRaceId, int customerTop, int petTop, int raceTop);
void tstLb_test6ListCustomerPetsMoreThan3Years(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId,int *pRaceId, int customerTop, int petTop, int raceTop);
void tstLb_test7ListPetsByType(Pet pets[],Race races[],int petTop,int raceTop,int petType,int *pPetId, int *pRaceId);

/*****Order : Customer and Pets*******/
void tstLb_test8OrderPetsByTypeAscAndShowAll(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId,int *pRaceId, int customerTop, int petTop, int raceTop);
void tstLb_test9OrderCustomerByNumberOfPetsAndShowAll(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId,int *pRaceId, int customerTop, int petTop, int raceTop);

/*****Average : Customer and Pets*******/
void tstLib_test10PetsAverageAgeAndShow(Pet pets[], int petTop,int *pPetId);
void tstLib_test11CustomerMaleFemaleAverageAndShow(Customer customers[],int *pCustomerId, int customerTop);
void tstLib_test12ListCustomerWithPetsSameGender(Customer customers[],Pet pets[], int *pCustomerId, int *pPetId, int customerTop, int petTop);

#endif /* UTN_PARCIALES_LIB_UTN_TEST_LIB_CUSTOMERPETSTEST_H_ */
