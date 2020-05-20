/*
 * CustomersPetsDataSets.h
 *  Created on: 14 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_PARCIALES_LIB_UTN_HELPERS_LIB_CUSTOMERSPETSDATASETS_H_
#define UTN_PARCIALES_LIB_UTN_HELPERS_LIB_CUSTOMERSPETSDATASETS_H_

#include "../utn_entities_lib/Customer.h"
#include "../utn_entities_lib/Pet.h"

void dsLib_getCustomerDataSet1(Customer customers[], int customerTop, int *pCustomerId);
void dsLib_getRacesDataSet1(Race races[], int racesTop, int *pRaceId);
void dsLib_getPetsDataSet1(Pet pets[], int petsTop, int *pPetId);


#endif /* UTN_PARCIALES_LIB_UTN_HELPERS_LIB_CUSTOMERSPETSDATASETS_H_ */
