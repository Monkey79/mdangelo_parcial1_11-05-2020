/*
 * CustomersPets.h
 *
 *  Created on: 11 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_PARCIALES_LIB_CUSTOMERSPETSMANAGER_H_
#define UTN_PARCIALES_LIB_CUSTOMERSPETSMANAGER_H_

#include "utn_entities_lib/Customer.h"
#include "utn_entities_lib/Pet.h"
#include "utn_entities_lib/Race.h"

void mngLib_initializeAll(Customer customers[], Pet pets[],Race races[], int customerTop, int petsTop, int raceTop);

/**********CRUD*********/
void mngLib_createCustomer(Customer customers[], int *pCustomerId,int customerTop);
void mngLib_updateCustomer(Customer customers[], int *pCustomerId, int customerTop);
void mngLib_deleteCustomer(Customer customers[],Pet pets[], int customerTop, int petTop);

void mngLib_createPet(Customer customers[], Pet pets[],Race races[], int *pPetId, int customerTop, int petTop, int raceTop);
void mngLib_deletePet(Pet pets[],int petTop);
void mngLib_updatePet(Pet pets[], Race races[], int petTop, int raceTop);

void mngLib_updateRace(Race races[], int raceTop);
/**********************/

void mngLib_orderPetsByType(Pet pets[], int petTop, int asc);
void mngLib_orderCustomerByNumberOfPets(Customer customers[],Pet pets[],int customerTop,int petTop, int asc);
void mngLib_getPetsAverageAges(Pet pets[],int petTop);
void mngLib_getPetsAverageAgesByType(Pet pets[],int petTop);
void mngLib_averageCustomerMaleFemale(Customer customers[], int customerTop);

void mngLib_showCustomerWithPetsSameGender(Customer customers[],Pet pets[],int  customerTop,int petTop);
void mngLib_showAllCustomers(Customer customers[], int customerTop);
void mngLib_showAllPets(Pet pets[], int petsTop);
void mngLib_showPetsByCustomer(Customer customers[], Pet pets[], int customerTop, int petsTop);

#endif /* UTN_PARCIALES_LIB_CUSTOMERSPETSMANAGER_H_ */
