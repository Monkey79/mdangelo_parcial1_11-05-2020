/*
 * VeterinaryBusiness.h
 *
 *  Created on: 20 may. 2020
 *      Author: monkey
 */

#ifndef UTN_MDANGELO_BUSINESS_VETERINARYBUSINESS_H_
#define UTN_MDANGELO_BUSINESS_VETERINARYBUSINESS_H_

#include "../utn_mdangelo_service/BreedService.h"
#include "../utn_mdangelo_service/PetService.h"
#include "../utn_mdangelo_service/OwnerService.h"

#include "../utn_mdangelo_utils/Utils.h"

void vtBsns_initializeAllVeterinary(Veterinary *veterinary, int testMode);
void vtnBsn_startVeterinary(Veterinary *veterinary);

void vtnBsns_createAPet(Veterinary *veterinary);
void vtnBsns_updateABreed(Veterinary *veterinary);
void vtnBsns_deletePet(Veterinary *veterinary);
void vtnBsns_updatePet(Veterinary *veterinary);
void vtnBsns_updateOwner(Veterinary *veterinary);
void vtnBsns_createOwner(Veterinary *veterinary);
void vtnBsns_deleteOwner(Veterinary *veterinary);

void vtnBsn_sortPetsByTypeAndShowAll(Veterinary *veterinary);
void vtnBsn_sortOwnerByPetsNumberAndOwnerName(Veterinary *veterinary);
void vtnBsn_showOwnerWithPets(Veterinary *veterinary);
void vtnBsn_showPetsMoreThan3YearsAndHisOwner(Veterinary *veterinary);
void vtnBsn_showPetsByType(Veterinary *veterinary);
void vtnBsn_showOwnerWithPetsSameGender(Veterinary *veterinary);

void vtnBsn_calculateAndShowAllInfo(Veterinary *veterinary);

#endif /* UTN_MDANGELO_BUSINESS_VETERINARYBUSINESS_H_ */
