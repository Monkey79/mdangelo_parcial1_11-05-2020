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
void dsLib_getRacesDataSet1(Race races[], int racesTop, int *pRaceId){
	char racesNames[][50]={"race_gato_name_1","race_gato_name_2","race_perro_name_3","race_perro_name_4","race_raro_name_5","racen_raro_name_6"};
	char racesCountries[][50]={"race_gato_country_1","race_gato_country_2","race_perro_country_3","race_perro_country_4","race_raro_country_5","racen_raro_country_6"};
	for(int i=0;i<racesTop;i++){
		races[i].id = ++(*pRaceId);
		strcpy(races[i].raceName, racesNames[i]);
		strcpy(races[i].raceCountry, racesCountries[i]);
		races[i].empty = FALSE;
	}
}

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
void dsLib_getPetsDataSet1(Pet pets[], int petsTop, int *pPetId){
	int ids[] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	int customerIds[] = { 1, 2, 3, 4, 5 }; //clientes_id
	int racesIds[]={1,2,3,4,5,6}; 		   //raza_id (2 razas por tipo)
	char petsNames[11][51] = { "mascota_1", "mascota_2", "mascota_3", "mascota_4", "mascota_5", "mascota_6", "mascota_7", "mascota_8", "mascota_9","mascota_10", "mascota_11" };
	int types[] = { 1, 1, 2, 2, 1, 2, 3, 2, 1, 1, 2 };
	int ages[] = { 1, 2, 4, 4, 4, 4, 4, 4, 1, 2, 2 };
	float weights[] = { 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22 };
	char genders[] = { 'M', 'F', 'M', 'F', 'M', 'F', 'M', 'F', 'F', 'F', 'F' };

	for (int i = 0; i < petsTop; i++) {
		pets[i].id = ids[i];
		strcpy(pets[i].name, petsNames[i]);
		pets[i].type = types[i];
		pets[i].age = ages[i];
		pets[i].weight = weights[i];
		pets[i].gender = genders[i];
		pets[i].empty = FALSE;
	}
	//cliente 1 tiene 2 mascotas (gatos)
	pets[0].customerId = customerIds[0];
	pets[0].raceId = racesIds[0];
	pets[1].customerId = customerIds[0];
	pets[1].raceId = racesIds[1];

	//cliente 2 tiene 3 mascotas (2 perros y 1 gato)
	pets[2].customerId = customerIds[1];
	pets[2].raceId = racesIds[2];
	pets[3].customerId = customerIds[1];
	pets[3].raceId = racesIds[3];
	pets[4].customerId = customerIds[1];
	pets[4].raceId = racesIds[0];

	//cliente 3 tiene 2 mascotas (1 perro y 1 raro)
	pets[5].customerId = customerIds[2];
	pets[5].raceId = racesIds[2];
	pets[6].customerId = customerIds[2];
	pets[6].raceId = racesIds[4];

	//cliente 4 tiene 1 mascota (1 perro)
	pets[7].customerId = customerIds[3];
	pets[7].raceId = racesIds[2];

	//cliente 5 tiene 3 mascotas (2 gatos y 1 perro)
	pets[8].customerId = customerIds[4];
	pets[8].raceId = racesIds[0];
	pets[9].customerId = customerIds[4];
	pets[9].raceId = racesIds[1];
	pets[10].customerId = customerIds[4];
	pets[10].raceId = racesIds[2];

	*pPetId = 11;
}
/******************************************************************************************************************/
