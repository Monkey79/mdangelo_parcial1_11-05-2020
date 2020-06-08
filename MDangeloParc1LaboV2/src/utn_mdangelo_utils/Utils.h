/*
 * Utils.h
 * Created on: 20 may. 2020
 * Author: mdangelo
 */

#ifndef UTN_MDANGELO_UTILS_UTILS_H_
#define UTN_MDANGELO_UTILS_UTILS_H_
#include "../utn_mdangelo_entities/MainEntities.h"


int utilLb_getLength(char *strVal);
void utilLb_cleanStrValue(char *strVal);
void utilLb_getYesNoQuestion(char *mssg,char *response);

/****Data Harcoded*****/
void utlLb_getBreedHarcodedData1(Breed breeds[], int *breedId);
void utlLb_getOwnersHarcodedData1(Owner owners[],int *ownerId);
void utlLb_getPetsHarcodedData1(Pet pets[], int *petId);
/**********************/

void utilLb_createMenuAndCallUserSelectionChecker(int *usrSelection,Veterinary *pVeterinary, void(*pFunction)(int,Veterinary *));

void utilLb_showOwnersOnly(Veterinary veterinary, int ownerTop);
void utilLb_showOwnersAndTheirPetsWithBreeds(Veterinary veterinary);
void utilLb_showAllPetsAndTheirBreeds(Pet pets[],Breed breeds[],int petTop, int breedTop);

void utilLb_sortPetsByType(Pet pets[], int petTop, int sortMode);
void utilLb_sortOwnerByNumberOfPetsAndOwnerName(Owner owners[],Pet pets[],int customerTop,int petTop, int asc);
void utilLb_showPethsMoreNYearWithOwner(Veterinary veterinary,int ownerTop, int petTop, int breedTop, int year);
void utilLb_showPetsByType(Pet pets[],Breed breeds[],int petTop,int breedTop, int petType);

void utilLb_calculateAndShowPetsAgeAverage(Pet pets[],int petTop);
void utilLb_calculatePetsAgeAverageByType(Pet pets[],int petTop);
void utilLb_calculatePercentageOwnerByGender(Owner owners[], int ownerTop);
void utilLb_showCustomerWithPetsSameGender(Owner owners[],Pet pets[],int customerTop,int petTop);

#endif /* UTN_MDANGELO_UTILS_UTILS_H_ */
