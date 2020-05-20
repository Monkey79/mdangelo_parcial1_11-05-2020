/*
 * Customer.h
 *  Created on: 11 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_CUSTOMER_H_
#define UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_CUSTOMER_H_

#include "DataType.h"

void cstLib_initCustomers(Customer customers[], int top);

int cstLib_createCustomer(Customer customers[],Customer customer, int customerTop);
int cstLib_deleteCustomer(Customer customers[], int customerId, int customerTop);
int cstLib_updateCustomer(Customer customers[], Customer customer, int customerTop);

void cstLib_showCustomers(Customer customers[], int top);
void cstLib_showCustomersIds(Customer customers[], int customerTop);

int cstLib_checkIdExists(Customer customers[],int customerId, int customerTop);
int cstLib_areCustomerCreated(Customer customers[], int customerTop);

#endif /* UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_CUSTOMER_H_ */
