/*
 * Race.h
 *
 *  Created on: 19 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_RACE_H_
#define UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_RACE_H_

#include "DataType.h"
void rcLb_initRaces(Race races[], int raceTop);
int rcLb_createRace(Race races[],Race race, int raceTop);
int rcLb_updateRace(Race races[], Race race, int raceTop);
int rcLb_deleteRace(Race races[], int raceId, int raceTop);
void rcLb_showAllRaces(Race races[], int raceTop);

void rcLb_getRaceByPetRaceId(Race races[], int petRaceId, int raceTop, Race *raceResult);
void rcLb_getRaceId(Race races[], int raceTop, int *pRaceId);

#endif /* UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_RACE_H_ */
