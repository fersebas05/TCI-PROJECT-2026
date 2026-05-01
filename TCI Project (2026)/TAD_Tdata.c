#include "TAD_Tdata.h" 

Tdata create_str_ast() {
	Tdata n = (Tdata)malloc(sizeof(struct dataType));
	n->nodeType = STR;
	n->strData = NULL;
	n->data = NULL;
	n->next = NULL;
	
	return n;
}

Tdata create_set() {
	Tdata n = (Tdata)malloc(sizeof(struct dataType));
	n->nodeType = SET;
	n->strData = NULL;
	n->data = NULL;
	n->next = NULL;
	
	return n;
}


Tdata create_list() {
	Tdata n = (Tdata)malloc(sizeof(struct dataType));
	n->nodeType = LIST;
	n->strData = NULL;
	n->data = NULL;
	n->next = NULL;
	
	return n;
}

// #Operaciones sobre LIST

void append(Tdata *list, Tdata elem) {
	Tdata nuevo = create_list();
	nuevo->data = elem;
	nuevo->next = NULL;
	
	if(*list == NULL) {
		*list = nuevo;
	}
	else{
		Tdata aux = *list;
		while(aux->next != NULL) {
			aux = aux->next;
		}
		aux->next = nuevo;
	}
}

int length (Tdata list) {
	int count = 0;
	
	while(list != NULL ){
		count++;
		list = list->next;
	}
	
	return count;
}

Tdata concat(Tdata list1, Tdata list2) {
	Tdata nuevo1 = create_list();
	nuevo1 = clone(list1);
	
	while(list2 != NULL) {
		append(&nuevo1, list2->data);
		list2 = list2->next;
	}
	
	return nuevo1;
}

Tdata search(Tdata list, Tdata elem) { //:::CORREGIDO::://
	Tdata buscado = create_list();
	
	while (list != NULL){ 
		if(str_comp(list->data->strData , elem->strData) == 0){
			buscado->data = elem;
			return buscado;
		}
		list = list->next;
	}
	
	return NULL;
}

Tdata copy_list(Tdata list) {
	Tdata nuevo = NULL;
	nuevo = clone(list);
	
	return nuevo;
}

Tdata str_to_list(Tdata strNode) {
	if(strNode == NULL || strNode->nodeType != STR){
		return NULL;
	}
	
	Tdata nuevo = NULL;
	str aux = strNode->strData;
	
	while (aux != NULL) {
		Tdata nodoAux = create_str_ast();
		nodoAux->strData = char_to_str(aux->dato);
		
		append(&nuevo, nodoAux);
		
		aux = aux->sig;
	}
	
	return nuevo;
}

Tdata list_to_str(Tdata listNode) {
	Tdata nuevo = create_str_ast();
	str aux = NULL;
	
	while(listNode != NULL)  {
		aux = concat_str(aux, listNode->data->strData);
		listNode = listNode->next;
	}
	
	nuevo->strData = aux;
	
	return nuevo;
}

//::::::::Funciones Generalizada para SET, LIST o STR(en algunos casos):::::::::
Tdata clone(Tdata list) {
	if(list == NULL){
		return NULL;
	}
	
	Tdata nuevo = NULL;
	
	if(list->nodeType == STR) {
		nuevo = create_str_ast();
		nuevo->strData = (list->strData);
	}
	else if(list->nodeType == SET || list->nodeType == LIST ){
		nuevo = (list->nodeType == SET) ? create_set() : create_list();
		
		Tdata aux = list;
		Tdata cab = NULL;
		Tdata cola = NULL;
		
		while (aux != NULL) {
			Tdata nodo_contenedor = (list->nodeType == SET) ? create_set() : create_list();
			
			nodo_contenedor->data = clone(aux->data);
			nodo_contenedor->next = NULL;
			
			if(cab == NULL) {
				cab = nodo_contenedor;
				cola = nodo_contenedor;
			}
			else{
				cola->next = nodo_contenedor;
				cola = nodo_contenedor;
			}
			
			aux = aux->next;
		}
		return cab;
	}
	return nuevo;
}

void mostrar_strNode(str cab){
	print_str(cab);
}

void mostrar_setNode(Tdata cab) {
	if(cab == NULL) {
		printf("\nLista Vacia...");
	}
	else {
		printf("{");
		while(cab != NULL){
			print_str(cab->strData);
			if(cab->next != NULL) printf(",");
			cab = cab->next;
		}
		printf("}");
	}
}

void mostrar_listNode(Tdata cab) {
	if(cab == NULL) {
		printf("\nLista Vacia...");
	}
	else {
		printf("[");
		while(cab != NULL){
			print_str(cab->strData);
			if(cab->next != NULL) printf(",");
			cab = cab->next;
		}
		printf("]");
	}
}

void mostrar_Tdata(Tdata cab) { //MODULO PRINCIPAL....
	if(cab == NULL) 
		printf("\nLista Vacia.");
	else {
		printf("( ");
		while(cab != NULL) {
			switch(cab->nodeType){
			case 1: mostrar_strNode(cab->strData); break;
			case 2: mostrar_setNode(cab->data); break;
			case 3: mostrar_listNode(cab->data); break;
			//case 4: mostrar_Tdata(cab->data); break;
			}
			if(cab->next != NULL) printf(" , ");
			cab = cab->next;
		}
		printf(" )");
	}
}


// #Operaciones sobre SET; 

/* Podria estar bien o muy mal */

void insert_set(Tdata *set, Tdata elem){
	Tdata nuevo = create_set();
	nuevo->data = elem;
	nuevo->next = NULL;
	
	if(*set == NULL) {
		*set = nuevo;
	}
	else{
		if(belongs(elem, *set) == 0){
			Tdata aux = *set;
			while(aux->next != NULL) {
				aux = aux->next;
			}
			aux->next = nuevo;
		}
	}
}

int belongs(Tdata elem, Tdata set){ // ::::De 10 este metodo::::
	while(set != NULL ){
		if(str_comp(set->data->strData , elem->strData) == 1){
			return 1;
		}
		set = set->next;
	}
	
	return 0; 
}

//:::::Tuve que hacerle un retoque a este :( , era buena la idea igualmente:::::
	
/*void remove_set(Tdata *set, Tdata elem){*/
/*	int eliminado;*/
/*	eliminado = belongs(*set, elem);*/
/*	if(eliminado == 1){*/
/*		printf("\n El elemento fue eliminado");*/
/*	}else{*/
/*		printf("\n El elemento ingresado no pertenece al conjunto");*/
/*	}*/
/*}*/

void remove_set(Tdata *set, Tdata elem) {
	Tdata aux =  *set;
	Tdata ant = NULL;
	
	while(aux->next != NULL && str_comp(aux->data->strData , elem->strData) == 0) {
		ant = aux;
		aux = aux->next;
	}
	
	if(str_comp(aux->data->strData, elem->strData) == 1) {
		if(ant == NULL) {
			*set = aux->next;
			aux->next = NULL;
			free(aux);
		}
		else {
			ant->next = aux->next;
			aux->next = NULL;
			free(aux);
		}
		printf("Elemento eliminado con exito...\n");
	}
	else{
		printf("\n::::::No se hallo el elemento a remover::::::\n");
	}
}

Tdata union_set(Tdata A, Tdata B) {
	Tdata nuevo = A;
	
	while(B != NULL) {
		if(belongs(B->data, A) == 0) {
			Tdata aux = clone(B->data);
			insert_set(&nuevo, aux);
		}
		B = B->next;
	}
	
	return nuevo;
}

Tdata intersection_set(Tdata A, Tdata B) {
	Tdata nuevo = NULL;
	
	while(A != NULL){
		if(belongs(A->data, B) == 1){
			Tdata n = clone(A->data);
			insert_set(&nuevo, n); 
		}
		A = A->next;
	}
	
	return nuevo;
}
	
Tdata difference_set(Tdata A, Tdata B) {
	Tdata nuevo = NULL;
	
	while(A != NULL) {
		if(belongs(A->data, B) == 0) {
			Tdata n = clone(A->data);
			insert_set(&nuevo, n);
		}
		A = A->next;
	}
	
	return nuevo;
}

int subset(Tdata A, Tdata B) {
	while(A != NULL) {
		if(!belongs(A->data, B)){
			return 0;
		}
		A = A->next;
	}
	
	return 1;
}

//::::::Habia dos maneras de hacerlo:::::::
int equals_set(Tdata A, Tdata B) { 
	if(subset(A, B) == 1 && subset(B,A) == 1) { //:::::Dos conjuntos son iguales si ambos son subconjuntos del otro::::::
		return 1;
	}
	else{
		return 0;
	}
}

Tdata cartesian_product(Tdata A, Tdata B) {
	Tdata nuevo = NULL; 
	/*Tdata auxA = A;*/
	
	while (A != NULL) {
		Tdata auxB = B;
		
		while(auxB != NULL) {
			Tdata par = NULL;
			append(&par, clone(A->data));
			append(&par, clone(auxB->data));
			
			insert_set(&nuevo, par);
			
			auxB = auxB->next;
		}
		
		A = A->next;
	}
	
	return nuevo;
}


