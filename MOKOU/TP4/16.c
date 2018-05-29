/*16) Se tiene una lista de enteros. Escribir una función que imprima los elementos de la lista en orden inverso.
NO acceder a la estructura, usar funciones del TAD.
UNRN
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Tipo_Dato
#include "pila_pointer.h"
#include "TADlist.h"
#define MAX 10

void Quits() {
	puts("Error: No hay memoria disponible.");
	exit(-1);
}

void InitNum(Lista_T *l) {
	if ( EstaVacia(*l) )
		InsertarPrimero(l, rand()%100+1);
	for (int i = 0; i < MAX-1; ++i) {
		InsertarUltimo(l, rand()%100+1);
	}
	printf("La lista es: \n");
	RecorrerLista(*l); // Imprime la lista
}

void CoparAPila(Pila_T *p, Lista_T *l) {
	for (int i = 1; i <= MAX; ++i)
		S_Push(p, DevolverDatoPosicion(*l, i));
}

void ImprimirPila(Pila_T *p) {
    int temp;
	printf("La cola es: \n");
	for (int i = 0; i < MAX; ++i) {
	    temp = S_Pop(p);
		printf("%d ", temp);
	}
	puts("");
}

int main() {
	srand(time(NULL));
	Pila_T pila = Crear_Pila(MAX);
	Lista_T lista = CrearLista();
	InitNum(&lista);
	CoparAPila(&pila, &lista);
	ImprimirPila(&pila);
	if ( Vaciar_Pila(&pila) && VaciarLista(&lista) ) {
		puts("La memoria ha sido vaciada.");
	}
}
