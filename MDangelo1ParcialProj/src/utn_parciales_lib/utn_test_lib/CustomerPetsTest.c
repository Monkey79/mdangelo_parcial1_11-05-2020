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
void tstLb_test1createPet(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId, int *pRaceId, int customerTop, int petTop, int raceTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	dsLib_getRacesDataSet1(races, raceTop, pRaceId); 				//harcodeo razas para las mascotas
	if(cstLib_areCustomerCreated(customers, customerTop)){
		mngLib_createPet(customers, pets,races, pPetId,customerTop, petTop, raceTop);
		hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop,races,raceTop);
	}else{
		printf("[Error] Debe crear primero un cliente antes de crear una mascota (y asi asociar dicha mascota con un cliente)\n");
	}
}
void tstLb_test2deletePet(Pet pets[],Race races[],int *pPetId, int *pRaceId,int petTop, int raceTop){
	dsLib_getPetsDataSet1(pets, petTop, pPetId); 			//harcodeo mascotas
	dsLib_getRacesDataSet1(races, raceTop, pRaceId); 		//harcodeo razas para las mascotas
	mngLib_deletePet(pets,petTop);
	hlpLb_showAllPetsAndTheirRaces(pets,petTop,races,raceTop);
}
void tstLb_test3UpdatePet(Pet pets[],Race races[],int *pPetId, int *pRaceId,int petTop, int raceTop){
	dsLib_getPetsDataSet1(pets, petTop, pPetId); 		//harcodeo mascotas
	dsLib_getRacesDataSet1(races, raceTop, pRaceId); 	//harcodeo razas para las mascotas
	mngLib_updatePet(pets,races,petTop,raceTop);
	hlpLb_showAllPetsAndTheirRaces(pets, petTop, races, raceTop);
}

void tstLb_test4CreateCustomer(Customer customers[],int *pCustomerId,int customerTop){
	mngLib_createCustomer(customers, pCustomerId, customerTop); //harcodeo clientes
	cstLib_showCustomers(customers, customerTop);
}
void tstLb_test4AUpdateCustomer(Customer customers[],int *pCustomerId,int customerTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	mngLib_updateCustomer(customers, pCustomerId, customerTop);
	cstLib_showCustomers(customers, customerTop);
}
void tstLb_test4BUpdateRace(Race races[],int raceTop, int *pRaceId){
	dsLib_getRacesDataSet1(races, raceTop, pRaceId); 	//harcodeo razas para las mascotas
	mngLib_updateRace(races,raceTop);
	rcLb_showAllRaces(races,raceTop);
}
void tstLb_test5DeleteCustomerAndHisPets(Customer customers[],Pet pets[],Race races[],int *pCustomerId,int *pPetId,int *pRaceId, int customerTop, int petTop,int raceTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId); 					//harcodeo mascotas
	if(cstLib_areCustomerCreated(customers, customerTop)){
		mngLib_deleteCustomer(customers,pets,customerTop,petTop);
		cstLib_showCustomers(customers, customerTop);
	}else{
		printf("[Error] Debe crear primero un cliente antes de borrar uno\n");
	}
}
/*************************************/

/*****List : Customer and Pets*******/
void tstLb_test6AListCustomerAndHisPets(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId,int *pRaceId, int customerTop, int petTop, int raceTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId);  //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId);					 //harcodeo mascotas
	dsLib_getRacesDataSet1(races, raceTop, pRaceId); 				 //harcodeo razas para las mascotas
	hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop,races,raceTop);
}
void tstLb_test6ListCustomerPetsMoreThan3Years(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId,int *pRaceId, int customerTop, int petTop, int raceTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId);  //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId);					 //harcodeo mascotas
	dsLib_getRacesDataSet1(races, raceTop, pRaceId); 				 //harcodeo razas para las mascotas
	hlpLb_showPetsByCustomersMore3YearsDataGrid(customers,customerTop, pets,petTop,races,raceTop);

}

void tstLb_test7ListPetsByType(Pet pets[],Race races[],int petTop,int raceTop,int petType,int *pPetId, int *pRaceId){
	dsLib_getPetsDataSet1(pets, petTop, pPetId);   		//harcodeo mascotas
	dsLib_getRacesDataSet1(races, raceTop, pRaceId); 	//harcodeo razas para las mascotas

	hlpLb_showPetsByTypeDataGrid(pets, races, petTop, raceTop, petType);

}
/*************************************/

/*****Order : Customer and Pets*******/
void tstLb_test8OrderPetsByTypeAscAndShowAll(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId,int *pRaceId, int customerTop, int petTop, int raceTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId);					//harcodeo mascotas
	dsLib_getRacesDataSet1(races, raceTop, pRaceId); 				//harcodeo razas para las mascotas
	printf("--->BEFORE------->:\n");
	hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop,races,raceTop);
	mngLib_orderPetsByType(pets,petTop,1); 							//1=asc 0=dsc
	printf("--->AFTER------->:\n");
	hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop,races,raceTop);
}

//Ordeno por cant mascotas si esta cantidades son iguales se ordena alfabeticamente por nombre en forma ascendente
//Responde puntos 14 y 15 juntos
void tstLb_test9OrderCustomerByNumberOfPetsAndShowAll(Customer customers[],Pet pets[],Race races[], int *pCustomerId, int *pPetId,int *pRaceId, int customerTop, int petTop, int raceTop){
	int mode = 1; //1=asc 0=dsc
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId);                    //harcodeo mascotas
	dsLib_getRacesDataSet1(races, raceTop, pRaceId); 				//harcodeo razas para las mascotas

	printf("--->BEFORE------->:\n");
	hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop,races,raceTop);
	mngLib_orderCustomerByNumberOfPets(customers, pets, customerTop, petTop,mode);
	printf("--->AFTER------->:\n");
	hlpLb_showPetsByCustomersDataGrid(customers,customerTop, pets,petTop,races,raceTop);
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

void tstLib_test12ListCustomerWithPetsSameGender(Customer customers[],Pet pets[], int *pCustomerId, int *pPetId, int customerTop, int petTop){
	dsLib_getCustomerDataSet1(customers, customerTop, pCustomerId); //harcodeo clientes
	dsLib_getPetsDataSet1(pets, petTop, pPetId);                    //harcodeo mascotas
	mngLib_showCustomerWithPetsSameGender(customers, pets, customerTop, petTop);
}
/*************************************/


