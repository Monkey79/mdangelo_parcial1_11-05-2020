/*
 * OwnerRepo.h
 *
 *  Created on: 20 may. 2020
 *      Author: monkey
 */

#ifndef UTN_MDANGELO_REPO_OWNERREPO_H_
#define UTN_MDANGELO_REPO_OWNERREPO_H_

#include "../utn_mdangelo_entities/MainEntities.h"

void ownerRp_initializeAllOwner(Owner owners[], int ownerTop);
int ownerRp_addOwner(Owner owners[], int ownerTop, Owner owner);
int ownerRp_updateOwner(Owner owners[], int ownerTop, Owner owner);
int ownerRp_deleteOwnerById(Owner owners[], int ownerTop, int ownerId);
#endif /* UTN_MDANGELO_REPO_OWNERREPO_H_ */
