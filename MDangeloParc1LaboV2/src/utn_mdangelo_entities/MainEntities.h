/*
 * MainEntities.h
 *  Created on: 20 may. 2020
 *  Author: mdangelo
 */

#ifndef UTN_MDANGELO_ENTITIES_MAINENTITIES_H_
#define UTN_MDANGELO_ENTITIES_MAINENTITIES_H_

#define TOP 50
#define TRUE 1
#define FALSE 0

#define OWNER_TOP 5 //10
#define PETS_TOP 11 //20
#define BREEDS_TOP 6

#define NO_EMPTY_SPACE "[Attention] There is NO more empty space!\n"
#define NO_ENTITY_FOUND "[Error] There is no customer with id=%d\n"
#define ENTITY_CREATION_OK "[Success] Entity id=%d creation success\n"

typedef struct{
	int id; 	//PK
	char breedName[TOP];
	char breedCountry[TOP];
	int empty;
}Breed;

typedef struct{
	int id;  			//PK
	int ownerId; 		//FK
	int breedId;		//FK
	char name[TOP];
	int type; 			//1=Cat 2=Dog 3=Exotic
	int age;
	float weight;
	char gender; 		//M=Male F=Female
	int empty;
}Pet;

typedef struct {
	int id; 		//PK
	char name[TOP];
	char lastName[TOP];
	char location[TOP];
	char phoneNumber[TOP];
	int age;
	char gender; //M=Male F=Female
	int empty;
}Owner;

typedef struct {
	Owner owners[OWNER_TOP];
	Pet pets[PETS_TOP];
	Breed breeds[BREEDS_TOP];

	/***id****/
	int ownerId;
	int petId;
	int breedId;
}Veterinary;

#endif /* UTN_MDANGELO_ENTITIES_MAINENTITIES_H_ */
