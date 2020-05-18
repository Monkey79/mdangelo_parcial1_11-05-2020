/*
 * DataType.h
 *
 *  Created on: 15 may. 2020
 *      Author: monkey
 */

#ifndef UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_DATATYPE_H_
#define UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_DATATYPE_H_

#define TOP 50

typedef struct{
	int id;  			//PK
	int customerId; 	//FK
	char name[TOP];
	int type; 			//1=Gato 2=perro 3=raro
	char race[TOP];
	int age;
	float weight;
	char gender; 		//M=Male F=Female
	int empty;
}Pet;

typedef struct {
	int id; //pk
	char name[TOP];
	char lastName[TOP];
	char location[TOP];
	char phoneNumber[TOP];
	int age;
	char gender; //M=Malse F=Female
	int empty;
}Customer;

#endif /* UTN_PARCIALES_LIB_UTN_ENTITIES_LIB_DATATYPE_H_ */
