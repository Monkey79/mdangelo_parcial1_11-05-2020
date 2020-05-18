/*
 * CustomersPets.c
 *
 *  Created on: 11 may. 2020
 *  Author: mdangelo
 */
#include "CustomersPetsManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

#include "utn_helpers_lib/Helper.h"

#define TRUE 1
#define FALSE 0


void _showAndGetCustomersIdsAvailable(Customer customers[], int customerTop, int *pCustomerId);
void _showAndGetPetsIdsAvailable(Pet pets[], int petsTop, int *pPetId);

void _orderCustomerPetsNumAsc(Customer *pCurrentCustomer, Customer *pNextCustomer, Pet pets[], int petTop);
void _orderCustomerPetsNumDsc(Customer *pCurrentCustomer, Customer *pNextCustomer, Pet pets[], int petTop);
void _orderPetsAsc(Pet *pCurrentPet, Pet *pNextPet);
void _orderPetsDsc(Pet *pCurrentPet, Pet *pNextPet);

void mngLib_initializeAll(Customer customers[], Pet pets[], int customerTop, int petsTop) {
	cstLib_initCustomers(customers, customerTop);
	ptLib_initPets(pets, petsTop);
}
/**************CRUD**********************************************************/
//Customer
void mngLib_createCustomer(Customer customers[], int *pCustomerId, int customerTop) {
	int success;
	Customer customer;

	printf("Ingrese nombre del cliente:");
	__fpurge(stdin);
	fgets(customer.name, 50, stdin);
	cmLib_cleanStrVal(customer.name);
	printf("Ingrese apellido del cliente:");
	__fpurge(stdin);
	fgets(customer.lastName, 50, stdin);
	cmLib_cleanStrVal(customer.lastName);
	printf("Ingrese localidad del cliente:");
	__fpurge(stdin);
	fgets(customer.location, 50, stdin);
	cmLib_cleanStrVal(customer.location);
	printf("Ingrese telefono del cliente:");
	__fpurge(stdin);
	fgets(customer.phoneNumber, 50, stdin);
	cmLib_cleanStrVal(customer.phoneNumber);
	do {
		printf("Ingrese la edad del cliente: ");
		scanf("%d", &customer.age);
	} while (customer.age < 0);
	do {
		printf("Ingrese genero del cliente [M | F]");
		__fpurge(stdin);
		scanf("%c", &customer.gender);
		customer.gender = toupper(customer.gender);
	} while (customer.gender != 'M' && customer.gender != 'F');

	customer.id = ++(*pCustomerId);
	customer.empty = FALSE;
	success = cstLib_createCustomer(customers, customer, customerTop);
	if (success)
		printf("[OK] Cliente id=%d creado con exito\n", customer.id);
}

void mngLib_deleteCustomer(Customer customers[],Pet pets[], int customerTop, int petTop){
	int success = TRUE;
	int customerIdDelete;
	_showAndGetCustomersIdsAvailable(customers, customerTop, &customerIdDelete);
	success =  cstLib_deleteCustomer(customers, customerIdDelete, customerTop);
	if (success) {
		printf("[OK] Cliente id=%d eliminado con exito. Se eliminaran todas las mascotas de este cliente\n");
		ptLib_deletePetsByCustomerId(pets,customerIdDelete,petTop);
	}
}
//Pet
void mngLib_createPet(Customer customers[], Pet pets[], int *pPetId, int customerTop, int petTop) {
	Pet petAux;
	int succes;
	int customerId;

	_showAndGetCustomersIdsAvailable(customers, customerTop, &customerId);
	petAux.customerId = customerId;

	printf("Ingrese nombre de la mascota:");
	__fpurge(stdin);
	fgets(petAux.name, 50, stdin);
	cmLib_cleanStrVal(petAux.name);

	do {
		printf("Ingrese el tipo de mascota [1=gato 2=perro 3=raro]");
		scanf("%d", &petAux.type);
	} while (petAux.type != 1 && petAux.type != 2 && petAux.type != 3);

	printf("Ingrese raza de la mascota: ");
	__fpurge(stdin);
	fgets(petAux.race, 50, stdin);
	cmLib_cleanStrVal(petAux.race);

	do {
		printf("Ingrese una edad valida para la mascota ");
		__fpurge(stdin);
		scanf("%d", &petAux.age);
	} while (petAux.age <= 0);
	do {
		printf("Ingrese un peso valido para la mascota ");
		__fpurge(stdin);
		scanf("%f", &petAux.weight);
	} while (petAux.weight <= 0.00);
	do {
		printf("Ingrese sexo de la mascota [M | F]");
		__fpurge(stdin);
		scanf("%c", &petAux.gender);
		petAux.gender = toupper(petAux.gender);
	} while (petAux.gender != 'M' && petAux.gender != 'F');

	petAux.id = ++(*pPetId);
	petAux.empty = FALSE;
	succes = ptLib_createPet(pets, petAux, petTop);
	if (succes) {
		printf("[OK] Mascota id=%d creada con exito.\n", petAux.id);
	}
}

void mngLib_updatePet(Pet pets[], int petTop) {
	int success = TRUE;
	int petId;
	Pet petUpdt;

	_showAndGetPetsIdsAvailable(pets, petTop, &petId);

	printf("Ingrese nuevo nombre de la mascota:");
	__fpurge(stdin);
	fgets(petUpdt.name, 50, stdin);
	cmLib_cleanStrVal(petUpdt.name);
	do {
		printf("Ingrese nuevo tipo de mascota [1=gato 2=perro 3=raro]");
		scanf("%d", &petUpdt.type);
	} while (petUpdt.type != 1 && petUpdt.type != 2 && petUpdt.type != 3);

	printf("Ingrese raza de la mascota: ");
	__fpurge(stdin);
	fgets(petUpdt.race, 50, stdin);
	cmLib_cleanStrVal(petUpdt.race);

	do {
		printf("Ingrese una edad valida para la mascota ");
		__fpurge(stdin);
		scanf("%d", &petUpdt.age);
	} while (petUpdt.age <= 0);
	do {
		printf("Ingrese un peso valido para la mascota ");
		__fpurge(stdin);
		scanf("%f", &petUpdt.weight);
	} while (petUpdt.weight <= 0.00);
	do {
		printf("Ingrese sexo de la mascota [M | F]");
		__fpurge(stdin);
		scanf("%c", &petUpdt.gender);
		petUpdt.gender = toupper(petUpdt.gender);
	} while (petUpdt.gender != 'M' && petUpdt.gender != 'F');
	petUpdt.id = petId;
	petUpdt.empty = FALSE;

	success = ptLib_updatePet(pets, petUpdt, petTop);
	if (success) {
		printf("[OK] Mascota id=%d actualizada con exito.\n", petUpdt.id);
	}
}
void mngLib_deletePet(Pet pets[], int petTop) {
	int success = TRUE;
	int petId;
	_showAndGetPetsIdsAvailable(pets, petTop, &petId);
	success = ptLib_deletePet(pets, petId, petTop);
	if (success) {
		printf("[OK] Mascota id=%d eliminada con exito.\n");
	}
}
/****************************************************************************************/

void mngLib_getPetsAverageAges(Pet pets[],int petTop){
	int cont=0;
	int ageAcum=0;
	for(int i=0;i<petTop;i++){
		if(!pets[i].empty){
			ageAcum+=pets[i].age;
			cont++;
		}
	}
	printf("Promedio de edades de todas las mascotas %.2f\n", (float) ageAcum/cont);
}
void mngLib_getPetsAverageAgesByType(Pet pets[],int petTop){
	int type1Cnt=0;
	int type2Cnt=0;
	int type3Cnt=0;
	int ageAcumType1=0;
	int ageAcumType2=0;
	int ageAcumType3=0;

	for(int i=0;i<petTop;i++){
		if(!pets[i].empty){
			switch (pets[i].type) {
				case 1:
					ageAcumType1+=pets[i].age;
					type1Cnt++;
					break;
				case 2:
					ageAcumType2+=pets[i].age;
					type2Cnt++;
					break;
				case 3:
					ageAcumType3+=pets[i].age;
					type3Cnt++;
					break;
			}
		}
	}
	printf("1-Promedio de edades de las mascotas tipo 1 (gato)=%.2f\n", (float)ageAcumType1/type1Cnt);
	printf("2-Promedio de edades de las mascotas tipo 2 (perro)=%.2f\n", (float)ageAcumType2/type2Cnt);
	printf("3-Promedio de edades de las mascotas tipo 3 (raro)=%.2f\n", (float)ageAcumType3/type3Cnt);
}

void mngLib_averageCustomerMaleFemale(Customer customers[], int customerTop){
	int maleCustomerCnt=0;
	int femaleCustomerCnt=0;
	int totalCustomerCnt=0;

	for(int i=0;i<customerTop;i++){
		if(!customers[i].empty){
			switch (customers[i].gender) {
				case 'F':
					femaleCustomerCnt++;
					break;
				case 'M':
					maleCustomerCnt++;
					break;
			}
			totalCustomerCnt++;
		}
	}
	printf("EL promedio de clientes varones es %.2f %\n",((float)maleCustomerCnt*100)/totalCustomerCnt);
	printf("EL promedio de clientes mujeres es %.2f %\n",((float)femaleCustomerCnt*100)/totalCustomerCnt);
}

void mngLib_orderPetsByType(Pet pets[], int petTop, int asc){
	for(int i=0;i<petTop;i++){
		for(int e=i+1;e<petTop;e++){
			if(asc)
				_orderPetsAsc(&pets[i],&pets[e]);
			else
				_orderPetsDsc(&pets[i],&pets[e]);
		}
	}
}
//Ordeno por cant mascotas si esta cantidades son iguales se ordena alfabeticamente por nombre en forma descendente
//Responde puntos 14 y 15 juntos
void mngLib_orderCustomerByNumberOfPets(Customer customers[],Pet pets[],int customerTop,int petTop, int asc){
	Customer customerAux;
	int currentNumOfPets;
	int nextNumOfPets;
	for(int i=0;i<customerTop;i++){
		for(int e=i+1;e<customerTop;e++){
			if(!customers[i].empty && !customers[e].empty){
				if(asc)
					_orderCustomerPetsNumAsc(&customers[i], &customers[e], pets, petTop);
				else
					_orderCustomerPetsNumDsc(&customers[i], &customers[e], pets, petTop);
			}

		}
	}
}

//*****************Private********************
void _showAndGetCustomersIdsAvailable(Customer customers[], int customerTop, int *pCustomerId) {
	do {
		printf("Atencion: De todos estos clientes elija un id valido del mismo: ");
		cstLib_showCustomersIds(customers, customerTop);
		scanf("%d", pCustomerId);
	} while (!cstLib_checkIdExists(customers, *pCustomerId, customerTop));
}

void _showAndGetPetsIdsAvailable(Pet pets[], int petsTop, int *pPetId) {
	do {
		printf("Atencion: De todos estas mascotas elija un id valido del mismo: ");
		ptLib_showPetsIds(pets, petsTop);
		scanf("%d", pPetId);
	} while (!ptLib_checkPetIdExists(pets, petsTop, *pPetId));
}

void _orderCustomerPetsNumAsc(Customer *pCurrentCustomer, Customer *pNextCustomer, Pet pets[], int petTop){
	Customer customerAux;
	int currentNumOfPets = ptLib_getNumberOfPetsByCustomerId(pets, petTop, pCurrentCustomer->id);
	int nextNumOfPets = ptLib_getNumberOfPetsByCustomerId(pets, petTop, pNextCustomer->id);
	if(currentNumOfPets>nextNumOfPets){
		customerAux = *pNextCustomer;
		*pNextCustomer = *pCurrentCustomer;
		*pCurrentCustomer = customerAux;
	}else if(currentNumOfPets==nextNumOfPets){
		if(strcmp(pCurrentCustomer->name, pNextCustomer->name)>0){
			customerAux = *pNextCustomer;
			*pNextCustomer = *pCurrentCustomer;
			*pCurrentCustomer = customerAux;
		}
	}
}

void _orderCustomerPetsNumDsc(Customer *pCurrentCustomer, Customer *pNextCustomer, Pet pets[], int petTop){
	Customer customerAux;
	int currentNumOfPets = ptLib_getNumberOfPetsByCustomerId(pets, petTop, pCurrentCustomer->id);
	int nextNumOfPets = ptLib_getNumberOfPetsByCustomerId(pets, petTop, pNextCustomer->id);
	if(currentNumOfPets<nextNumOfPets){
		customerAux = *pNextCustomer;
		*pNextCustomer = *pCurrentCustomer;
		*pCurrentCustomer = customerAux;
	}else if(currentNumOfPets==nextNumOfPets){
		if(strcmp(pCurrentCustomer->name, pNextCustomer->name)<0){
			customerAux = *pNextCustomer;
			*pNextCustomer = *pCurrentCustomer;
			*pCurrentCustomer = customerAux;
		}
	}
}

void _orderPetsAsc(Pet *pCurrentPet, Pet *pNextPet){
	Pet petAux;
	if(!pCurrentPet->empty && !pNextPet->empty){
		if(pCurrentPet->type > pNextPet->type){
			petAux = *pNextPet;
			*pNextPet = *pCurrentPet;
			*pCurrentPet = petAux;
		}
	}
}
void _orderPetsDsc(Pet *pCurrentPet, Pet *pNextPet){
	Pet petAux;
	if(!pCurrentPet->empty && !pNextPet->empty){
		if(pCurrentPet->type < pNextPet->type){
			petAux = *pNextPet;
			*pNextPet = *pCurrentPet;
			*pCurrentPet = petAux;
		}
	}
}
