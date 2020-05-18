/*
 * Customer.h
 *  Created on: 11 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_CUSTOMER_H_
#define UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_CUSTOMER_H_

#include "DataType.h"
/*#define TOP 51

typedef struct {
	int id; //pk
	char name[TOP];
	char lastName[TOP];
	char location[TOP];
	char phoneNumber[TOP];
	int age;
	char gender; //M=Malse F=Female
	int empty;
}Customer;*/

void cstLib_initCustomers(Customer customers[], int top);

int cstLib_createCustomer(Customer customers[],Customer customer, int customerTop);
int cstLib_deleteCustomer(Customer customers[], int customerId, int customerTop);
int cstLib_updateCustomer(Customer customers[], Customer customer, int customerTop);

void cstLib_showCustomers(Customer customers[], int top);
void cstLib_showCustomersIds(Customer customers[], int customerTop);

int cstLib_checkIdExists(Customer customers[],int customerId, int customerTop);
int cstLib_areCustomerCreated(Customer customers[], int customerTop);

#endif /* UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_CUSTOMER_H_ */
