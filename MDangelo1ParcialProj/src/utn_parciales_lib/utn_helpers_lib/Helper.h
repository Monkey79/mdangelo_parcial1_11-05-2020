/*
 * Commons.h
 *
 *  Created on: 13 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_PARCIALES_LIB_UTN_HELPERS_LIB_HELPER__C_
#define UTN_PARCIALES_LIB_UTN_HELPERS_LIB_HELPER__C_

#include "../utn_entities_lib/DataType.h"

void buildMenuAndGetUserSelection(int *pUsrSelection);

int cmLib_getLength(char *strVal);
void cmLib_cleanStrVal(char *strVal);

void hlpLb_showOneCustomer(Customer customer, int *pFirstTime);
void hlpLb_showAllPets(Pet pets[], int petsTop);
void hlpLb_showPetsByCustomersDataGrid(Customer customers[], int customerTop, Pet pets[], int petTop,Race races[], int raceTop);
void hlpLb_showPetsByCustomersMore3YearsDataGrid(Customer customers[], int customerTop, Pet pets[], int petTop, Race races[], int raceTop);
void hlpLb_showPetsByTypeDataGrid(Pet pets[],Race races[], int petTop,int raceTop, int petType);

#endif /* UTN_PARCIALES_LIB_UTN_HELPERS_LIB_HELPER__C_ */
