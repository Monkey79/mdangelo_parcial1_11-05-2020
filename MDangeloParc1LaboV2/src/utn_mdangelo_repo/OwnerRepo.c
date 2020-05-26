/*
 * OwnerRepo.c
 *
 *  Created on: 20 may. 2020
 *  Author: mdangelo
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "OwnerRepo.h"

int _getOwnerEmptyIndex(Owner owners[], int ownerTop);
int _getCustomerIndexById(Owner owners[],int ownerId, int ownerTop);

void ownerRp_initializeAllOwner(Owner owners[], int ownerTop) {
	for (int i = 0; i < ownerTop; i++) {
		owners[i].id = -1;
		owners[i].empty = TRUE;
	}
}
int ownerRp_addOwner(Owner owners[], int ownerTop, Owner owner) {
	int success = TRUE;
	int i = _getOwnerEmptyIndex(owners, ownerTop);
	if(i>=0){
		owners[i] = owner;
		owners[i].empty = FALSE;
	}else{
		printf(NO_EMPTY_SPACE);
		success = FALSE;
	}
	return success;
}
int ownerRp_updateOwner(Owner owners[], int ownerTop, Owner owner){
	int success = TRUE;
	int i = _getCustomerIndexById(owners, owner.id, ownerTop);
	if(i>=0){
		owner.id = owners[i].id;
		owners[i] = owner;
		owners[i].empty = FALSE;
	}else{
		printf(NO_ENTITY_FOUND);
		success = FALSE;
	}
	return success;
}
int ownerRp_deleteOwnerById(Owner owners[], int ownerTop, int ownerId){
	int success = TRUE;
	int i = _getCustomerIndexById(owners, ownerId, ownerTop);
	if(i>=0){
		owners[i].id = -1;
		owners[i].empty = TRUE;
	}else{
		printf(NO_ENTITY_FOUND, ownerId);
		success = FALSE;
	}
	return success;
}
/******Private functions************/
int _getOwnerEmptyIndex(Owner owners[], int ownerTop){
	int i;
	for(i=0;i<ownerTop && !owners[i].empty;i++);
	return i;
}

int _getCustomerIndexById(Owner owners[],int ownerId, int ownerTop){
	int i;
	for(i=0;i<ownerTop && owners[i].id!=ownerId;i++);
	return i;
}

