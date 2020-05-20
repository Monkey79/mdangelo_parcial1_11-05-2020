/*
 * Race.c
 *  Created on: 19 may. 2020
 *  Author: mdangelo
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "Race.h"

#define TRUE 1
#define FALSE 0

int _getFreeRaceIndx(Race races[],int raceTop);
int _getRaceIndexById(Race races[],int raceId,int raceTop);
int _checkIfRaceIdIsValid(Race races[], int raceTop, int raceId);

void rcLb_initRaces(Race races[], int raceTop){
	for(int i=0;i<raceTop;i++){
		races[i].id = -1;
		races[i].empty = TRUE;
	}
}
int rcLb_createRace(Race races[],Race race, int raceTop){
	int success=TRUE;
	int i=_getFreeRaceIndx(races, raceTop);
	if(i>=0){
		races[i] = race;
	}else{
		success = FALSE;
		printf("[Error] There is no more free space\n");
	}
	return success;
}

int rcLb_updateRace(Race races[], Race race, int raceTop){
	int success = TRUE;
	int i = _getRaceIndexById(races, race.id, raceTop);
	if(i>=0){
		races[i]=race;
	}else{
		success = FALSE;
		printf("[Error] No race was found with id=%d\n",race.id);
	}
	return success;
}
int rcLb_deleteRace(Race races[], int raceId, int raceTop){
	int success=TRUE;
	int i = _getRaceIndexById(races, raceId, raceTop);
	if(i>=0){
		races[i].id = -1;
		races[i].empty = TRUE;
	}else{
		success = FALSE;
		printf("[Error] There is no races with id=%d\n", raceId);
	}
	return success;
}

void rcLb_getRaceByPetRaceId(Race races[], int petRaceId, int raceTop, Race *raceResult){
	int i = _getRaceIndexById(races,petRaceId,raceTop);
	*raceResult = races[i];
}

void rcLb_showAllRaces(Race races[], int raceTop){
	printf("Race_ID\t\t");
	printf("Race_Name\t\t");
	printf("Race_Country\n");
	for(int i=0;i<raceTop;i++){
		printf("%d %30s %25s \n", races[i].id, races[i].raceName, races[i].raceCountry);
	}
}

void rcLb_getRaceId(Race races[], int raceTop, int *pRaceId){
	printf("--Atencion: De las siguientes razas disponibles seleccione el ID el cual pertenece a su mascota----\n");
	do{
		rcLb_showAllRaces(races, raceTop);
		__fpurge(stdin);
		scanf("%d", pRaceId);
	}while(!_checkIfRaceIdIsValid(races, raceTop, *pRaceId));
}

/*******Private*******************/
int _checkIfRaceIdIsValid(Race races[], int raceTop, int raceId){
	int i;
	for(i=0;i<raceTop && races[i].id != raceId; i++);
	return (races[i].id==raceId);
}

int _getRaceIndexById(Race races[],int raceId,int raceTop){
	int i;
	for(i=0;i<raceTop && races[i].id != raceId;i++);
	return i;
}
int _getFreeRaceIndx(Race races[],int raceTop){
	int i;
	for(i=0;i<raceTop && !races[i].empty;i++);
	return i;
}


