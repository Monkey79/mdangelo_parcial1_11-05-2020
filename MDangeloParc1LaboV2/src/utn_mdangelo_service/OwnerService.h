/*
 * OwnerService.h
 *
 *  Created on: 20 may. 2020
 *      Author: monkey
 */

#ifndef UTN_MDANGELO_SERVICE_OWNERSERVICE_H_
#define UTN_MDANGELO_SERVICE_OWNERSERVICE_H_

#include "../utn_mdangelo_utils/Utils.h"
#include "../utn_mdangelo_repo/OwnerRepo.h"

void ownerSvc_initializeAllOwners(Owner owners[], int ownerTop);
void ownerSvc_getValidOwnerId(Owner owners[],int *ownerId, int ownerTop);

int ownerSvc_createOwner(Owner owners[], int ownerTop, int *ownerId);
int ownerSvc_updateOwner(Owner owners[],int ownerTop, int ownerUpdId);
int ownerSvc_deleteOwner(Owner owners[],int ownerTop, int ownerDeleteId);
int ownerSvc_checkIsValidOwnerId(Owner owners[],int ownerId);

void ownerSvc_getLength(Owner owners[],int *len,int ownerTop);

#endif /* UTN_MDANGELO_SERVICE_OWNERSERVICE_H_ */
