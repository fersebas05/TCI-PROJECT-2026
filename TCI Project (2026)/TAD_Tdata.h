#ifndef TAD_TDATA_H
#define TAD_TDATA_H

#include "TAD_String.h"

#define STR 1
#define SET 2
#define LIST 3

typedef struct dataType{
	int nodeType;
	union {
		str strData;
		struct {
			struct dataType *data;
			struct dataType *next;
		};
	};
}TdataType;

typedef TdataType *Tdata;

// #Funciones de Creacion...
Tdata create_str_ast();
Tdata create_list();
Tdata create_set();


// #Operaciones sobre LIST....

void append(Tdata *list, Tdata elem);
int length(Tdata list);
Tdata copy_list(Tdata list);
Tdata concat(Tdata list1, Tdata list2);
Tdata search(Tdata list, Tdata elem);
Tdata str_to_list(Tdata strNode);
Tdata list_to_str(Tdata listNode);

// #Operaciones sobre SET....
void insert_set(Tdata *set, Tdata elem);
int belongs(Tdata elem, Tdata set);
void remove_set(Tdata *set, Tdata elem); 
   // Operaciones Algebraicas sobre SET...
Tdata union_set(Tdata A, Tdata B);
Tdata intersection_set(Tdata A, Tdata B);
Tdata difference_set(Tdata A, Tdata B);
int subset(Tdata A, Tdata B);
int equals_set(Tdata A, Tdata B);
Tdata cartesian_product(Tdata A, Tdata B);

// #Funciones Generalizadas....
void mostrar_Tdata(Tdata list);
Tdata clone(Tdata list);


#endif
