#include "TAD_Tdata.h"

/*::::::::::::::::::::::::::*/
void menuPrueba();
void pruebaList();
void pruebaSet();

/*:::::::::::::::::::::::::*/

int main() {
	//#Code;
	
	Tdata s1 = create_str_ast();
	s1->strData = load_str();
	
	mostrar_Tdata(s1);
	
	menuPrueba();
	return 0;
}

void menuPrueba(){
	int opcion;
	printf("[0].Prueba_List \n[1].Prueba_Set\n Ingrese --> ");
	scanf("%d", &opcion);
	(opcion == 0) ? pruebaList() : pruebaSet();
}

void pruebaList() {
	Tdata s1 = create_str_ast();
	s1->strData = load2_str("Hola");
	
	Tdata s2 = create_str_ast();
	s2->strData = load2_str("Mundo");
	
	Tdata s3 = create_str_ast();
	s3->strData = load2_str("soy");
	
	Tdata s4 = create_str_ast();
	s4->strData = load2_str("Anto xd");
	
	Tdata s5 = create_str_ast();
	s5->strData = load2_str("Hello");
	
	Tdata s6 = create_str_ast();
	s6->strData = load2_str("Im");
	
	Tdata s7 = create_str_ast();
	s7->strData = load2_str("Anto xd");
	
	Tdata B = NULL;
	
	Tdata Lista =  NULL ;
	append(&Lista, s1);
	append(&Lista, s2);
	append(&Lista, s3);
	append(&Lista, s4);
	
	printf("\nLista: "); // Mostrar Lista...
	mostrar_Tdata(Lista);
	
	B = copy_list(Lista); // Hacer una copia de la lista...
	printf("\n\nSoy un clon: ");
	mostrar_Tdata(B);
	
	Tdata C = concat(Lista, B); // Concatenacion de dos listas...
	printf("\n\nConcatenar: ");
	mostrar_Tdata(C);
	
	Tdata D = search(Lista, s3); // Buscar un elemento de la Lista, y devolver el elemento....
	printf("\n\nBuscar: ");
	mostrar_Tdata(D);
	
	Tdata E = str_to_list(s4); // Conversion de STR --> LIST....
	printf("\n\nConversion STR --> LIST: ");
	mostrar_Tdata(E);
	
	Tdata F = list_to_str(Lista); // Conversion de LIST --> STR....
	printf("\n\nConversion LIST --> STR: ");
	mostrar_Tdata(F);
}

void pruebaSet() {
	/*Carga de los Nodos STR_AST*/
	Tdata s1 = create_str_ast();
	s1->strData = load2_str("Hola");
	
	Tdata s2 = create_str_ast();
	s2->strData = load2_str("Mundo");
	
	Tdata s3 = create_str_ast();
	s3->strData = load2_str("soy");
	
	Tdata s4 = create_str_ast();
	s4->strData = load2_str("Anto xd");
	
	Tdata s5 = create_str_ast();
	s5->strData = load2_str("Hello");
	
	Tdata s6 = create_str_ast();
	s6->strData = load2_str("Im");
	
	Tdata s7 = create_str_ast();
	s7->strData = load2_str("Anto xd");
	
	/*Carga de los nodos SET*/
	Tdata setA = NULL;
	Tdata setB = NULL;
	insert_set(&setA, s1);
	insert_set(&setA, s2);
	insert_set(&setA, s3);
	insert_set(&setA, s4);
	
	insert_set(&setB, s5);
	insert_set(&setB, s6);
	insert_set(&setB, s7);
	
	
	/*Pruebas de las Funcionalidades para SET*/
	printf("\nConjunto A = "); mostrar_Tdata(setA);
	printf("\n\nConjunto B = "); mostrar_Tdata(setB);
	
	printf("\n\nEliminar el elemento 3: ");
	remove_set(&setA, s3);
	printf("Nuevo A = "); mostrar_Tdata(setA);

	printf("\n\nInterseccion entre A y B: ");
	Tdata setI = intersection_set(setA, setB);
	mostrar_Tdata(setI);
	
	printf("\n\nDiferencia entre A y B: ");
	Tdata setD = difference_set(setA, setB);
	mostrar_Tdata(setD);
	
	printf("\n\nsetI es subconjunto de setA? --> "); (subset(setB, setA) == 1) ? printf("Si") : printf("No");
	printf("\n\nsetI es subconjunto de setB? --> "); (subset(setB, setA) == 1) ? printf("Si") : printf("No");
	printf("\n\nsetD es subconjunto de setA? --> "); (subset(setB, setA) == 1) ? printf("Si") : printf("No");
	printf("\n\nsetB es subconjunto de setA? --> "); (subset(setB, setA) == 1) ? printf("Si") : printf("No");
	
	printf("\n\nEliminar elemento 4 de A....");
	remove_set(&setA, s4);
	printf("\nNuevo A = "); mostrar_Tdata(setA);
	
	printf("\n\nsetD es igual a nuevo setA ---> ");
	(equals_set(setD, setA) == 1) ? printf("Si") : printf("No"); //::::::Este printeo es buenisimo xd::::::
	
	printf("\n\n Insertar el elemento 4 a setA ---> "); print_str(s4->strData);
	insert_set(&setA, s4);
	
	printf("\n\nUnion entre A y B = ");
	mostrar_Tdata(union_set(setA, setB));
	
	Tdata AxB = cartesian_product(setA, setB);
	printf("\n\n\nProducto Cartesiano A y B = ");
	mostrar_Tdata(AxB);
}
