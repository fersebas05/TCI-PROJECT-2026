#ifndef TAD_STRING_H
#define TAD_STRING_H

#include <stdio.h>
#include <stdlib.h>

typedef struct nodo_str{ // Estructura de Cadena de Caracteres a partir de Listas Enlazadas....
	char dato;
	struct nodo_str *sig;
}Tnodo_str;

typedef Tnodo_str *str;

str load_str(); // Carga por Consola...
str load2_str(const char* txt); //Carga por Texto en Codigo
int str_comp(str cad1, str cad2); // Comparacion de Cadenas
str concat_str(str cad1, str cad2); // Concatenacion de Cadenas
str char_to_str(char m); // Conversion de Char --> STR

void print_str(str cad1); // Muestra la cadena de Caracteres...


#endif
