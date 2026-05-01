#include "TAD_String.h"

// #Operaciones Privadas de STR....

str create_str() {
	str n = (str)malloc(sizeof(Tnodo_str));
	n->dato = ' ';
	n->sig = NULL;
	
	return n;
}

void append_str(str *cab, str nuevo) {
	if(*cab == NULL) {
		*cab = nuevo;
	}
	else{
		str ult = *cab;
		while (ult->sig != NULL) {
			ult = ult->sig;
		}
		ult->sig = nuevo;
	}
}


// #Operaciones Principales de STR....

str load_str() {
	printf("Ingrese cadena --> "); fflush(stdin);
	str nuevo = NULL;
	char m = getchar();
	while(m != EOF && m != '\n' && m != '\0') {
		str aux = create_str();
		aux->dato = m;
		append_str(&nuevo, aux);
		m = getchar();
	}
	
	return nuevo;
}

str load2_str(const char *texto) {
	str nuevo = NULL;
	int i = 0;
	while(texto[i] != '\0') {
		str aux = create_str();
		aux->dato = texto[i];
		append_str(&nuevo, aux);
		i++;
	}
	
	return nuevo;
}

int str_comp(str cad1, str cad2) {
	while((cad1 != NULL && cad2 != NULL) && (cad1->dato == cad2->dato) ) {
		cad1 = cad1->sig;
		cad2 = cad2->sig;
	}
	
	if(cad1 == NULL && cad2 == NULL) {
		return 1;
	}
	else{
		return 0;
	}
}

str concat_str(str cad1, str cad2) {
	str nuevo = NULL;
	
	while(cad1 != NULL){
		str aux = create_str();
		aux->dato = cad1->dato;
		append_str(&nuevo, aux);
		cad1 = cad1->sig;
	}
	
	append_str(&nuevo, cad2);
	
	return nuevo;
}

str char_to_str(char m) {
	str nuevo = create_str();
	nuevo->dato = m;
	
	return nuevo;
}

void print_str(str cab){
	if(cab == NULL) 
		printf("\nla lista esta vacia");
	else{
		while(cab != NULL) {
			printf("%c",cab->dato);
			cab = cab->sig;
		}
	}
}


	
