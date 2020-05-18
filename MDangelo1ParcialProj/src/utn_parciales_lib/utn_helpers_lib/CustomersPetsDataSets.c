/*
 * CustomersPetsDataSets.c
 *  Created on: 14 may. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "CustomersPetsDataSets.h"

#define TRUE 1
#define FALSE 0

/**********************************************DataSet-1********************************************************************/
/*
 *Existen 5 clientes (hay lugar para 10 maximo).
 *Existen 10 mascotas (hay lugar para 20 maximo).
 *Dos gatos los tiene un cliente (sexo femenino).
 *Dos perros y un gato los tiene un cliente (sexo masculino).
 *Un pitbull y una iguana los tiene una chica.
 *Un labrador los tiene un chico.
 *Dos gatos y un bulldog una señor.
 */
void dsLib_getCustomerDataSet1(Customer customers[], int customerTop, int *pCustomerId) {
	int ids[5] = { 1, 2, 3, 4, 5 };
	//char names[5][51] = { "cliente_z", "cliente_2", "cliente_a", "cliente_4", "cliente_5" }; //para ordenar por nombre en casa de cant-mascotas iguales
	char names[5][51] = { "cliente_1", "cliente_2", "cliente_3", "cliente_4", "cliente_5" };
	char lastNames[5][51] = { "cliente_apell_1", "cliente_apell_2", "cliente_apell_3", "cliente_apell_4", "cliente_apell_5" };
	char locations[5][51] = { "cliente_1_location", "cliente_2_location", "cliente_3_location", "cliente_4_location", "cliente_5_location" };
	char phoneNumbers[5][51] = { "1111111", "2222222", "33333333", "44444444", "555555555" };
	int ages[5] = { 10, 10, 12, 12, 10 };
	char genders[5] = { 'F', 'M', 'F', 'M', 'M' };

	for (int i = 0; i < customerTop; i++) {
		customers[i].id = ids[i];
		strcpy(customers[i].name, names[i]);
		strcpy(customers[i].lastName, lastNames[i]);
		strcpy(customers[i].location, locations[i]);
		strcpy(customers[i].phoneNumber, phoneNumbers[i]);
		customers[i].age = ages[i];
		customers[i].gender = genders[i];
		customers[i].empty = FALSE;
	}
	*pCustomerId = 5;
}
void dsLib_getPetsDataSet1(Pet pets[], int petsTop, int *pPetId) {
	int ids[] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	int customerIds[] = { 1, 2, 3, 4, 5 };
	char petsNames[11][51] = { "mascota_1", "mascota_2", "mascota_3", "mascota_4", "mascota_5", "mascota_6", "mascota_7", "mascota_8", "mascota_9",
			"mascota_10", "mascota_11" };
	int types[] = { 1, 1, 2, 2, 1, 2, 3, 2, 1, 1, 2 };
	char races[11][51] = { "gato-a", "gato-b", "raza-b", "raza-c", "gato-d", "pitbull\0", "iguana", "labrador", "gato-i", "gato-j", "bulldog" };
	int ages[] = { 1, 2, 4, 4, 4, 4, 4, 4, 1, 2, 2 };
	float weights[] = { 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22 };
	char genders[] = { 'M', 'F', 'M', 'F', 'M', 'F', 'M', 'F', 'M', 'F', 'F' };

	for (int i = 0; i < petsTop; i++) {
		pets[i].id = ids[i];
		strcpy(pets[i].name, petsNames[i]);
		pets[i].type = types[i];
		strcpy(pets[i].race, races[i]);
		pets[i].age = ages[i];
		pets[i].weight = weights[i];
		pets[i].gender = genders[i];
		pets[i].empty = FALSE;
	}
	//cliente 1 tiene 2 mascotas
	pets[0].customerId = customerIds[0];
	pets[1].customerId = customerIds[0];
	//cliente 2 tiene 3 mascotas
	pets[2].customerId = customerIds[1];
	pets[3].customerId = customerIds[1];
	pets[4].customerId = customerIds[1];
	//cliente 3 tiene 2 mascotas
	pets[5].customerId = customerIds[2];
	pets[6].customerId = customerIds[2];
	//cliente 4 tiene 1 mascota
	pets[7].customerId = customerIds[3];
	//cliente 5 tiene 3 mascotas
	pets[8].customerId = customerIds[4];
	pets[9].customerId = customerIds[4];
	pets[10].customerId = customerIds[4];

	*pPetId = 11;
}
/******************************************************************************************************************/
