/*
 * Utils.c
 *
 *  Created on: 20 may. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Utils.h"

#define ASC_MODE_SORT 1
#define DSC_MODE_SORT 0

//*****Private Functions**********************
void _orderPetsAsc(Pet *pCurrentPet, Pet *pNextPet);
void _orderPetsDsc(Pet *pCurrentPet, Pet *pNextPet);
void _orderOwnerPetsNumDsc(Owner *pCurrentOwner, Owner *pNextOwner, Pet pets[], int petTop);
void _orderOwnerPetsNumDsc(Owner *pCurrentOwner, Owner *pNextOwner, Pet pets[], int petTop);

void _getBreedsHacordedData1(Breed breeds[], int *breedId);
void _getOwnersHarcodedData1(Owner owners[], int *ownerId);
void _getPetsHarcodedData(Pet pets[], int *petId);

void _getBreedById(Breed breeds[], int breedId, Breed *breed);
void _showOwnerContent(Owner owner);
void _showPetAndTheirBreed(Pet pet,Breed breed);
void _getTypeDescription(char typeDescription[], int typeInt);
void _showOwnerGridHeader();
void _showPetsGridHeader();
void _showPetsBreedConcatOwnerGridHeader();
//*******************************************
void utilLb_createMenuAndCallUserSelectionChecker(int *usrSelection,Veterinary *pVeterinary, void(*pFunction)(int,Veterinary *)){
	do{
		printf("**************Menu***************************\n");
		printf("1-Alta de mascota\n");
		printf("2-Baja de mascota\n");
		printf("3-Modificacion de mascota\n");

		printf("4-Alta de Dueño\n");
		printf("5-Baja de Dueño (y sus mascotas)\n");
		printf("6-Modificacion de Dueño\n");

		printf("7-Actualizar raza\n");

		printf("8-Listar clientes con mas de una mascota\n");
		printf("9-Listar mascotas con mas de 3 años (y sus dueños)\n");
		printf("10-Listar mascotas por tipo (1=gato 2=perro 3=exotico)\n");
		printf("11-Listar dueños con mascotas del mismo sexo\n");

		printf("12-Ordenar mascotas por tipo (1=gato 2=perro 3=exotico) y mostrarlas\n");
		printf("13-Calcular estadisticas y mostrarlas\n");
		printf("14-Ordenar dueños por cant de mascotas y alfabeticamens (mostrarlas)\n");

		printf("0-SALIR\n");
		scanf("%d",usrSelection);
		pFunction(*usrSelection,pVeterinary);
	}while(*usrSelection>0 && *usrSelection<15);
}

int utilLb_getLength(char *strVal) {
	int i;
	for (i=0; *(strVal + i); i++);
	return i;
}

void utilLb_cleanStrValue(char *strVal) {
	int i = utilLb_getLength(strVal) - 1;
	if (*(strVal + i)=='\n') *(strVal+i)='\0';
}
void utilLb_getYesNoQuestion(char *mssg,char *response){
	do{
		printf(mssg);
		__fpurge(stdin);
		scanf("%c",response);
		*response = toupper(*response);
	}while(*response!='S' && *response!='N');
}

/***************Data Harcoded**************/
void utlLb_getBreedHarcodedData1(Breed breeds[], int *breedId){
	_getBreedsHacordedData1(breeds, breedId); //raza
}
void utlLb_getOwnersHarcodedData1(Owner owners[],int *ownerId){
	_getOwnersHarcodedData1(owners, ownerId); //dueños
}
void utlLb_getPetsHarcodedData1(Pet pets[], int *petId){
	_getPetsHarcodedData(pets, petId); //mascotas
}
/*****************************************/

void utilLb_showOwnersOnly(Veterinary veterinary, int ownerTop){
	_showOwnerGridHeader();
	for(int i=0;i<ownerTop;i++){
		if(!veterinary.owners[i].empty)_showOwnerContent(veterinary.owners[i]);
	}
}

void utilLb_showOwnersAndTheirPetsWithBreeds(Veterinary veterinary){
	int noPet;
	Breed petBreed;
	for(int i=0;i<OWNER_TOP;i++){
		noPet = FALSE;
		_showOwnerGridHeader();
		_showOwnerContent(veterinary.owners[i]);
		_showPetsGridHeader();
		for(int e=0;e<PETS_TOP;e++){
			if(!veterinary.pets[e].empty && veterinary.pets[e].ownerId == veterinary.owners[i].id){
				_getBreedById(veterinary.breeds, veterinary.pets[e].breedId, &petBreed);
				_showPetAndTheirBreed(veterinary.pets[e],petBreed);
				noPet = TRUE;
			}
		}
		if(!noPet)printf("-----Este dueño no posee mascotas----\n");
	}
}

void utilLb_showAllPetsAndTheirBreeds(Pet pets[],Breed breeds[],int petTop, int breedTop){
	Breed petBreed;
	_showPetsGridHeader();
	for(int e=0;e<petTop;e++){
		if(!pets[e].empty){
			_getBreedById(breeds, pets[e].breedId, &petBreed);
			_showPetAndTheirBreed(pets[e],petBreed);
		}
	}
}

void utilLb_sortPetsByType(Pet pets[], int petTop, int sortMode){
	for(int i=0;i<petTop;i++){
		for(int e=i+1;e<petTop;e++){
			if(sortMode==ASC_MODE_SORT)
				_orderPetsAsc(&pets[i],&pets[e]);
			else
				_orderPetsDsc(&pets[i],&pets[e]);
		}
	}
}

void utilLb_showOwnerThaHavePets(Owner owners[],Pet pets[],int ownerTop, int petTop){
	int petNum=0;
	_showOwnerGridHeader();
	for(int i=0;i<ownerTop;i++){
		if(!owners[i].empty){
			petNum = petSv_getNumberOfPetsByOwnerId(pets,PETS_TOP, owners[i].id);
			if(petNum>=1)
				_showOwnerContent(owners[i]);
			else
				printf("--Este dueño NO tiene mascotas--\n");
		}
	}
}

void utilLb_showPethsMoreNYearWithOwner(Veterinary veterinary,int ownerTop, int petTop, int breedTop, int year){
	Breed petBreed;
	_showPetsBreedConcatOwnerGridHeader();
	for(int e=0;e<ownerTop;e++){
		for(int i=0;i<petTop;i++){
			if(!veterinary.owners[e].empty && !veterinary.pets[i].empty){
				if(veterinary.owners[e].id == veterinary.pets[i].ownerId && veterinary.pets[i].age >= year){
					breedSvc_getBreedByPetId(veterinary.breeds,breedTop, veterinary.pets[i].breedId,&petBreed);
					_showPetAndTheirBreedConcatOwner(veterinary.pets[i],petBreed,veterinary.owners[e]);
				}else{
					printf("--Este dueño NO tiene mascotas con mas %d años--\n", year);
				}
			}
		}
	}
}

void utilLb_showPetsByType(Pet pets[],Breed breeds[],int petTop,int breedTop, int petType){
	Breed petBreed;
	_showPetsGridHeader();
	for(int e=0;e<petTop;e++){
		if(!pets[e].empty && pets[e].type==petType){
			_getBreedById(breeds, pets[e].breedId, &petBreed);
			_showPetAndTheirBreed(pets[e],petBreed);
		}
	}
}

//Ordeno por cant mascotas si esta cantidades son iguales se ordena alfabeticamente por nombre en forma descendente
//Responde puntos 14 y 15 juntos
void utilLb_sortOwnerByNumberOfPetsAndOwnerName(Owner owners[],Pet pets[],int customerTop,int petTop, int asc){
	Owner ownerAux;
	int currentNumOfPets;
	int nextNumOfPets;
	for(int i=0;i<customerTop;i++){
		for(int e=i+1;e<customerTop;e++){
			if(!owners[i].empty && !owners[e].empty){
				if(asc)
					_orderOwnerPetsNumAsc(&owners[i], &owners[e], pets, petTop);
				else
					_orderOwnerPetsNumDsc(&owners[i], &owners[e], pets, petTop);
			}

		}
	}
}
void utilLb_calculateAndShowPetsAgeAverage(Pet pets[],int petTop){
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

void utilLb_calculatePetsAgeAverageByType(Pet pets[],int petTop){
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

void utilLb_calculatePercentageOwnerByGender(Owner owners[], int ownerTop){
	int maleCustomerCnt=0;
	int femaleCustomerCnt=0;
	int totalCustomerCnt=0;

	for(int i=0;i<ownerTop;i++){
		if(!owners[i].empty){
			switch (owners[i].gender) {
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

void utilLb_showCustomerWithPetsSameGender(Owner owners[],Pet pets[],int customerTop,int petTop){
	int sameGender = FALSE;
	int firstTime = TRUE;
	printf("---Dueños con mascotas del mismo sexo---\n");
	for(int i=0;i<customerTop;i++){
		petSv_checkPetsAreSameGenderByOwnerId(pets, petTop, owners[i].id, &sameGender);
		if(sameGender){
			if(firstTime){
				_showOwnerGridHeader();
				firstTime = FALSE;
			}
			_showOwnerContent(owners[i]);
		}

	}
}

//*****Private Functions**********************
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

void _orderOwnerPetsNumAsc(Owner *pCurrentOwner, Owner *pNextOwner, Pet pets[], int petTop){
	Owner ownerAux;
	int currentNumOfPets = petSv_getNumberOfPetsByOwnerId(pets, petTop, pCurrentOwner->id);
	int nextNumOfPets = petSv_getNumberOfPetsByOwnerId(pets, petTop, pNextOwner->id);

	if(currentNumOfPets>nextNumOfPets){
		ownerAux = *pNextOwner;
		*pNextOwner = *pCurrentOwner;
		*pCurrentOwner = ownerAux;
	}else if(currentNumOfPets==nextNumOfPets){
		if(strcmp(pCurrentOwner->name, pNextOwner->name)>0){
			ownerAux = *pNextOwner;
			*pNextOwner = *pCurrentOwner;
			*pCurrentOwner = ownerAux;
		}
	}
}

void _orderOwnerPetsNumDsc(Owner *pCurrentOwner, Owner *pNextOwner, Pet pets[], int petTop){
	Owner ownerAux;
	int currentNumOfPets = petSv_getNumberOfPetsByOwnerId(pets, petTop, pCurrentOwner->id);
	int nextNumOfPets = petSv_getNumberOfPetsByOwnerId(pets, petTop, pNextOwner->id);

	if(currentNumOfPets<nextNumOfPets){
		ownerAux = *pNextOwner;
		*pNextOwner = *pCurrentOwner;
		*pCurrentOwner = ownerAux;

	}else if(currentNumOfPets==nextNumOfPets){
		if(strcmp(pCurrentOwner->name, pNextOwner->name)<0){
			ownerAux = *pNextOwner;
			*pNextOwner = *pCurrentOwner;
			*pCurrentOwner = ownerAux;
		}
	}
}

void _getBreedById(Breed breeds[], int breedId, Breed *breed){
	for(int i=0;i<BREEDS_TOP;i++){
		if(!breeds[i].empty && breeds[i].id == breedId){
			*breed = breeds[i];
		}
	}
}
void _showOwnerContent(Owner owner){
	if(!owner.empty)
		printf("%d \t%20s \t%22s \t%26s \t%10s \t%12d \t%12c\n", owner.id, owner.name, owner.lastName, owner.location,owner.phoneNumber, owner.age, owner.gender);
}

void _showPetAndTheirBreed(Pet pet,Breed breed){
	char typeDescrip[50]={0};
	_getTypeDescription(typeDescrip, pet.type);
	printf("%13d %15s %20s %24s %26s %10d %18.2f %12c\n", pet.id, typeDescrip,pet.name, breed.breedName,breed.breedCountry, pet.age, pet.weight, pet.gender);
}

void _showPetAndTheirBreedConcatOwner(Pet pet, Breed breed, Owner owner){
	char typeDescrip[50]={0};
	_getTypeDescription(typeDescrip, pet.type);
	printf("%13d %15s %20s %24s %26s %10d %18.2f %12c %20s %22s \n", pet.id, typeDescrip,pet.name, breed.breedName,breed.breedCountry, pet.age,
			pet.weight,pet.gender,owner.name,owner.location);
}


void _getTypeDescription(char typeDescription[], int typeInt){
	char descpAux[8];
	switch (typeInt) {
		case 1:
			strcpy(descpAux,"1=Gato\0");
			break;
		case 2:
			strcpy(descpAux,"2=Perro\0");
			break;
		case 3:
			strcpy(descpAux,"3=Raro\0");
			break;
		default:
			break;
	}
	strcpy(typeDescription, descpAux);
}

void _showOwnerGridHeader(){
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
	printf("\tMascota_Nombre");
	printf("\tMascota_Raza_Nombre");
	printf("\tMascota_Raza_Pais");
	printf("\tMascota_Edad");
	printf("\tMascota_Peso");
	printf("\tMascota_Sexo\n");
}

void _showPetsBreedConcatOwnerGridHeader(){
	printf("\tMascota_ID");
	printf("\tMascota_Tipo");
	printf("\tMascota_Nombre");
	printf("\tMascota_Raza_Nombre");
	printf("\tMascota_Raza_Pais");
	printf("\tMascota_Edad");
	printf("\tMascota_Peso");
	printf("\tMascota_Sexo");
	printf("\tCliente_Nombre");
	printf("\tCliente_Localidad\n");
}

//Razas
void _getBreedsHacordedData1(Breed breeds[], int *breedId){
	int ids[6] = { 1, 2, 3, 4, 5,6 };
	char breedNames[][50]={"race_gato_name_1","race_gato_name_2","race_perro_name_3","race_perro_name_4","race_raro_name_5","racen_raro_name_6"};
	char breedCountries[][50]={"race_gato_country_1","race_gato_country_2","race_perro_country_3","race_perro_country_4","race_raro_country_5","racen_raro_country_6"};
	for(int i=0;i<BREEDS_TOP;i++){
		breeds[i].id = ids[i];
		strcpy(breeds[i].breedName, breedNames[i]);
		strcpy(breeds[i].breedCountry, breedCountries[i]);
		breeds[i].empty = FALSE;
	}
	*breedId = 6;
}
//Dueño
void _getOwnersHarcodedData1(Owner owners[], int *ownerId){
	int ids[5] = { 1, 2, 3, 4, 5 };
	char names[5][51] = { "cliente_1", "cliente_2", "cliente_3", "cliente_4", "cliente_5" };
	char lastNames[5][51] = { "cliente_apell_1", "cliente_apell_2", "cliente_apell_3", "cliente_apell_4", "cliente_apell_5" };
	char locations[5][51] = { "cliente_1_location", "cliente_2_location", "cliente_3_location", "cliente_4_location", "cliente_5_location" };
	char phoneNumbers[5][51] = { "1111111", "2222222", "33333333", "44444444", "555555555" };
	int ages[5] = { 10, 10, 12, 12, 10 };
	char genders[5] = { 'F', 'M', 'F', 'M', 'M' };

	for (int i = 0; i < OWNER_TOP; i++) {
		owners[i].id = ids[i];
		strcpy(owners[i].name, names[i]);
		strcpy(owners[i].lastName, lastNames[i]);
		strcpy(owners[i].location, locations[i]);
		strcpy(owners[i].phoneNumber, phoneNumbers[i]);
		owners[i].age = ages[i];
		owners[i].gender = genders[i];
		owners[i].empty = FALSE;
	}
	*ownerId = 5;
}
//Mascotas
void _getPetsHarcodedData(Pet pets[], int *petId){
	int ids[] = { 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	int customerIds[] = { 1, 2, 3, 4, 5 }; //clientes_id
	int racesIds[]={1,2,3,4,5,6}; 		   //raza_id (2 razas por tipo)
	char petsNames[11][51] = { "mascota_1", "mascota_2", "mascota_3", "mascota_4", "mascota_5", "mascota_6", "mascota_7", "mascota_8", "mascota_9","mascota_10", "mascota_11" };
	int types[] = { 1, 1, 2, 2, 1, 2, 3, 2, 1, 1, 2 };
	int ages[] = { 1, 2, 4, 4, 4, 4, 4, 4, 1, 2, 2 };
	float weights[] = { 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22, 22.22 };
	char genders[] = { 'M', 'F', 'M', 'F', 'M', 'F', 'M', 'F', 'F', 'F', 'F' };

	for (int i = 0; i < PETS_TOP; i++) {
		pets[i].id = ids[i];
		strcpy(pets[i].name, petsNames[i]);
		pets[i].type = types[i];
		pets[i].age = ages[i];
		pets[i].weight = weights[i];
		pets[i].gender = genders[i];
		pets[i].empty = FALSE;
	}
	//cliente 1 tiene 2 mascotas (gatos)
	pets[0].ownerId = customerIds[0];
	pets[0].breedId = racesIds[0];
	pets[1].ownerId = customerIds[0];
	pets[1].breedId = racesIds[1];

	//cliente 2 tiene 3 mascotas (2 perros y 1 gato)
	pets[2].ownerId = customerIds[1];
	pets[2].breedId = racesIds[2];
	pets[3].ownerId = customerIds[1];
	pets[3].breedId = racesIds[3];
	pets[4].ownerId = customerIds[1];
	pets[4].breedId = racesIds[0];

	//cliente 3 tiene 2 mascotas (1 perro y 1 raro)
	pets[5].ownerId = customerIds[2];
	pets[5].breedId = racesIds[2];
	pets[6].ownerId = customerIds[2];
	pets[6].breedId = racesIds[4];

	//cliente 4 tiene 1 mascota (1 perro)
	pets[7].ownerId = customerIds[3];
	pets[7].breedId = racesIds[2];

	//cliente 5 tiene 3 mascotas (2 gatos y 1 perro)
	pets[8].ownerId = customerIds[4];
	pets[8].breedId = racesIds[0];
	pets[9].ownerId = customerIds[4];
	pets[9].breedId = racesIds[1];
	pets[10].ownerId = customerIds[4];
	pets[10].breedId = racesIds[2];

	*petId = 11;
}

