/*
 * Commons.c
 *
 *  Created on: 13 may. 2020
 *  Author: mdangelo
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

#include "Helper.h"

#define TRUE 1
#define FALSE 0

void _showCustomerGridHeader();
void _showPetsGridHeader();
void _showCustomerContent(Customer customer);
void _showPetContent(Pet pet);

int cmLib_getLength(char *strVal) {
	int i;
	for (i=0; *(strVal + i); i++);
	return i;
}

void cmLib_cleanStrVal(char *strVal) {
	int i = cmLib_getLength(strVal) - 1;
	if (*(strVal + i)=='\n') *(strVal+i)='\0';
}



void buildMenuAndGetUserSelection(int *pUsrSelection){
	printf("**************Menu***************************\n");
	printf("\t1-Alta de mascota\n");
	printf("\t2-Baja de mascota\n");
	printf("\t3-Actualizacion de mascota\n");
	printf("\t4-Alta de Cliente (dueño)\n");
	printf("\t5-Baja de Cliente (dueño)\n");

	printf("\t6-Ordenar mascotas por tipo\n");
}


/***************************Data Gris************************************************************/
void hlpLb_showAllPets(Pet pets[], int petsTop) {
	printf("==============MASCOTAS====================\n");
	ptLib_showPets(pets, petsTop);
	printf("==========================================\n");
}

void hlpLb_showPetsByCustomersDataGrid(Customer customers[], int customerTop, Pet pets[], int petTop) {
	char petTypeAux[50] = { 0 };
	int havePets;
	printf("********************************************************Clientes y sus mascotas******************************************************************\n");
	for (int i = 0; i < customerTop; i++) {
		if(!customers[i].empty){
			havePets = FALSE;
			_showCustomerGridHeader();
			_showCustomerContent(customers[i]);
			_showPetsGridHeader();
			for (int e = 0; e < petTop; e++) {
				if(!pets[e].empty){
					if (customers[i].id == pets[e].customerId) {
						havePets = TRUE;
						_showPetContent(pets[e]);
					}
				}
			}
			if (!havePets) printf("--NO tiene mascotas!--\n");
		}
	}
	printf("**************************************************************************************************************************************************\n");
}

void hlpLb_showPetsByCustomersMore3YearsDataGrid(Customer customers[], int customerTop, Pet pets[], int petTop){
	char petTypeAux[50] = {0};
	int havePetsMore3Years;
	printf("********************************************************Clientes y sus mascotas (cons mas de 3 años)******************************************************************\n");

	for (int i = 0; i < customerTop; i++) {
		if(!customers[i].empty){
			havePetsMore3Years = FALSE;
			_showCustomerGridHeader();
			_showCustomerContent(customers[i]);
			_showPetsGridHeader();
			for (int e = 0; e < petTop; e++) {
				if(!pets[e].empty){
					if (customers[i].id == pets[e].customerId && pets[e].age > 3) {
						havePetsMore3Years = TRUE;
						_showPetContent(pets[e]);
					}
				}
			}
			if (!havePetsMore3Years) printf("--NO tiene mascotas con mas de 3 años!--\n");
		}
	}
	printf("**************************************************************************************************************************************************\n");

}
void hlpLb_showPetsByTypeDataGrid(Pet pets[], int petTop, int petType){
	printf("********************************************************Mascotas (por tipo)******************************************************************\n");
	int matchType;
	int firstTime = TRUE;
	for(int i=0;i<petTop;i++){
		if(!pets[i].empty){
			matchType=FALSE;
			if(pets[i].type == petType){
				if(firstTime){
					_showPetsGridHeader();
					firstTime = FALSE;
				}
				_showPetContent(pets[i]);
				matchType = TRUE;
			}
			//if(!matchType) printf("\t\t--->No hay mascota con este tipo=%d<-----\n",petType);
		}
	}
	printf("**************************************************************************************************************************************************\n");
}


//********************Private**************************
void _showCustomerContent(Customer customer){
	printf("%d \t%20s \t%22s \t%26s \t%10s \t%12d \t%12c\n", customer.id, customer.name, customer.lastName, customer.location,customer.phoneNumber, customer.age, customer.gender);
}

void _showPetContent(Pet pet){
	char petTypeAux[50] = { 0 };
	ptLib_getTypeDescription(petTypeAux, pet.type);
	printf("%13d\t %11s %18s %10d %18.2f %12c\n", pet.id, petTypeAux, pet.race, pet.age, pet.weight, pet.gender);
}

void _showCustomerGridHeader() {
	printf("-------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("Cliente_ID");
	printf("\tCliente_Nombre");
	printf("\t\tCliente_Apellido");
	printf("\tCliente_Localidad");
	printf("\tCliente_Telefono");
	printf("\tCliente_Edad");
	printf("\tCliente_Sexo\n");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------\n");
}

void _showPetsGridHeader() {
	printf("\tMascota_ID");
	printf("\tMascota_Tipo");
	printf("\tMascota_Raza");
	printf("\tMascota_Edad");
	printf("\tMascota_Peso");
	printf("\tMascota_Sexo\n");
}
