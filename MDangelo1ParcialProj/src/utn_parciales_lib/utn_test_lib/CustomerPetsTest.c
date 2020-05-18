/*
 * CustomerPetsTest.c
 *  Created on: 15 may. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "CustomerPetsTest.h"

/*****CRUD : Customer and Pets*******/
void tstLb_test1createPet(Customer customers[],Pet pets[], int *pCustomerId, int *pPetId, int customerTop, int petTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	if(cstLib_areCustomerCreated(customers, customerTop)){
		mngLib_createPet(customers, pets, pPetId,customerTop, petTop);
		hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop);
	}else{
		printf("[Error] Debe crear primero un cliente antes de crear una mascota (y asi asociar dicha mascota con un cliente)\n");
	}
}
void tstLb_test2deletePet(Pet pets[],int *pPetId,int petTop){
	dsLib_getPetsDataSet1(pets, petTop, pPetId); //harcodeo mascotas
	mngLib_deletePet(pets,petTop);
	hlpLb_showAllPets(pets, petTop);
}
void tstLb_test3UpdatePet(Pet pets[],int *pPetId,int petTop){
	dsLib_getPetsDataSet1(pets, petTop, pPetId); //harcodeo mascotas
	mngLib_updatePet(pets,petTop);
	hlpLb_showAllPets(pets, petTop);
}
void tstLb_test4CreateCustomer(Customer customers[],int *pCustomerId,int customerTop){
	mngLib_createCustomer(customers, pCustomerId, customerTop);
	cstLib_showCustomers(customers, customerTop);
}
void tstLb_test5DeleteCustomerAndHisPets(Customer customers[],Pet pets[],int *pCustomerId,int *pPetId, int customerTop, int petTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId); 					//harcodeo mascotas
	if(cstLib_areCustomerCreated(customers, customerTop)){
		mngLib_deleteCustomer(customers,pets,customerTop,petTop);
		hlpLb_showPetsByCustomersDataGrid(customers,customerTop,pets,petTop);
	}else{
		printf("[Error] Debe crear primero un cliente antes de borrar uno\n");
	}
}
/*************************************/

/*****List : Customer and Pets*******/
void tstLb_test6ListCustomerPetsMoreThan3Years(Customer customers[],Pet pets[], int *pCustomerId, int *pPetId, int customerTop, int petTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId);  //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId);					 //harcodeo mascotas
	hlpLb_showPetsByCustomersMore3YearsDataGrid(customers,customerTop, pets,petTop);
}

void tstLb_test7ListPetsByType(Pet pets[],int petTop, int petType,int *pPetId){
	dsLib_getPetsDataSet1(pets, petTop, pPetId);   		//harcodeo mascotas
	hlpLb_showPetsByTypeDataGrid(pets, petTop, petType);
}
/*************************************/

/*****Order : Customer and Pets*******/
void tstLb_test8OrderPetsByTypeAscAndShowAll(Customer customers[],Pet pets[], int *pCustomerId, int *pPetId, int customerTop, int petTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId);					//harcodeo mascotas
	printf("--->BEFORE------->:\n");
	hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop);
	mngLib_orderPetsByType(pets,petTop,1); 							//1=asc 0=dsc
	printf("--->AFTER------->:\n");
	hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop);
}

//Ordeno por cant mascotas si esta cantidades son iguales se ordena alfabeticamente por nombre en forma ascendente
//Responde puntos 14 y 15 juntos
void tstLb_test9OrderCustomerByNumberOfPetsAndShowAll(Customer customers[],Pet pets[], int *pCustomerId, int *pPetId, int customerTop, int petTop){
	int mode = 1; //1=asc 0=dsc
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId);                    //harcodeo mascotas
	printf("--->BEFORE------->:\n");
	hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop);
	mngLib_orderCustomerByNumberOfPets(customers, pets, customerTop, petTop,mode);
	printf("--->AFTER------->:\n");
	hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop);
}
/*************************************/

/*****Average : Customer and Pets*******/
//Aca contesto preguntas 16 y 17
void tstLib_test10PetsAverageAgeAndShow(Pet pets[], int petTop,int *pPetId){
	dsLib_getPetsDataSet1(pets, petTop, pPetId); //harcodeo mascotas
	mngLib_getPetsAverageAges(pets, petTop);
	mngLib_getPetsAverageAgesByType(pets, petTop);
}
void tstLib_test11CustomerMaleFemaleAverageAndShow(Customer customers[],int *pCustomerId, int customerTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	mngLib_averageCustomerMaleFemale(customers, customerTop);
}
/*************************************/


