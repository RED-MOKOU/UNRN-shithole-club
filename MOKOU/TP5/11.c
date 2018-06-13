/*11) Implementar el TAD Arbol Binario de Búsqueda (ABB) con elementos de tipo Tipo_Dato (Tipo_Dato en
un tipo donde los operadores =;<;> tienen sentido). Se puede utilizar la siguiente estructura:

struct Nodo {
	struct Nodo *izq;
	Tipo_Dato dato;
	struct Nodo *der;
};

typedef struct Nodo* Arbol_T;

El TAD debe disponer de las siguientes funciones:

a. Arbol_T CrearArbol(Tipo_Dato dato);
b. int InsertarElemento(Arbol_T *arbol, Tipo_Dato x );
c. void InOrder(Arbolt_T arbol);
d. void PostOrder(Arbolt_T arbol);
e. void PreOrder(Arbolt_T arbol);
f. Arbol_T EliminarElemento(Arbol_T *arbol, Tipo_Dato dato);
g. int Existe(Arbol_T arbol, Tipo_Dato dato);
*/
	
#include <stdio.h>
#include <stdlib.h>
typedef int Tipo_Dato;
#include "ABB.c"

int main() {
	Arbol_T arbol = NULL;
	Menu(arbol);
	if ( arbol != NULL ) {
		puts("Destuyendo el arbol...");
		DestruirArbol(arbol);
		puts("El arbol ha sido destruido.");
	}
	return 0;
}
