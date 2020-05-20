/*
 * Customer.c
 *  Created on: 11 may. 2020
 *  Author: mdangelo
 */

#include "../utn_entities_lib/Customer.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>


#define TRUE 1
#define FALSE 0

int _getCustomerEmptyIndex(Customer customers[],int customerTop);
int _getCustomerIndexById(Customer customers[],int customerId,int customerTop);

void cstLib_initCustomers(Customer customers[], int top){
	for(int i=0;i<top;i++){
		customers[i].id=-1;
		customers[i].empty = TRUE;
	}
}

int cstLib_createCustomer(Customer customers[],Customer customer, int customerTop){
	int success = TRUE;
	int i = _getCustomerEmptyIndex(customers, customerTop);
	if(i>=0){
		customers[i] = customer;
	}else{
		printf("[Attention] There is NO more empty space!\n");
		success = FALSE;
	}
	return success;
}
int cstLib_updateCustomer(Customer customers[], Customer customer, int customerTop){
	int success = TRUE;
	int i = _getCustomerIndexById(customers, customer.id, customerTop);
	if(i>=0){
		customer.id = customers[i].id;
		customers[i] = customer;
	}else{
		printf("[Error] There is no customer with id=%d\n");
		success = FALSE;
	}
	return success;
}
int cstLib_deleteCustomer(Customer customers[], int customerId, int customerTop){
	int success = TRUE;
	int i = _getCustomerIndexById(customers, customerId, customerTop);
	if(i>=0){
		customers[i].id = -1;
		customers[i].empty = TRUE;
	}else{
		printf("[Error]The is no customer with id=%d\n", customerId);
		success = FALSE;
	}
	return success;
}

int cstLib_areCustomerCreated(Customer customers[], int customerTop){
	int i;
	for(i=0;i<customerTop && customers[i].empty;i++);
	return (!customers[i].empty)?TRUE:FALSE;
}

void cstLib_showCustomers(Customer customers[], int top){
	printf("ID");
	printf("\t Nombre");
	printf("\t\t Apellido");
	printf("\t\t Localidad");
	printf("\t\t Telefono");
	printf("\t Edad");
	printf("\t Sexo\n");

	for(int i=0;i<top;i++){
		if(!customers[i].empty){
			printf("%d %16s %22s %26s %10s %12d %8c\n", customers[i].id, customers[i].name, customers[i].lastName, customers[i].location,customers[i].phoneNumber, customers[i].age, customers[i].gender);
		}
	}
}
void cstLib_showCustomersIds(Customer customers[], int customerTop){
	printf("\nCliente_ID");
	printf("\tCliente_Nombre\n");
	for(int i=0;i<customerTop && !customers[i].empty;i++){
		printf("%d \t%10s \n",customers[i].id,customers[i].name);
	}
}

int cstLib_checkIdExists(Customer customers[],int customerId, int customerTop){
	int i;
	for(i=0;i<customerTop && customers[i].id!=customerId;i++);
	return (customers[i].id==customerId);
}

//**************Private********************
int _getCustomerEmptyIndex(Customer customers[],int customerTop){
	int i;
	for(i=0;i<customerTop && !customers[i].empty;i++);
	return i;
}
int _getCustomerIndexById(Customer customers[],int customerId,int customerTop){
	int i;
	for(i=0;i<customerTop && customers[i].id!=customerId;i++);
	return i;
}


