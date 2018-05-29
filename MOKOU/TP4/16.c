/*16) Se tiene una lista de enteros. Escribir una función que imprima los elementos de la lista en orden inverso.
NO acceder a la estructura, usar funciones del TAD.
UNRN
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Tipo_Dato
#include "pila_pointer.h"
#define MAX 10

void Quits() {
	puts("Error: No hay memoria disponible.");
	exit(-1);
}

Tipo_Dato *InitArr() {
	int *out = NULL;
	if ( (out = (int*)malloc(MAX*sizeof *out)) == NULL )
		Quits();
	printf("El array es: ");
	for (int i = 0; i < MAX; ++i) {
		out[i] = rand()%100+1;
		printf("%d ", out[i]);
	}
	puts("");
	return out;
}

void CoparAPila(Pila_T *p, Tipo_Dato *numeros) {
	for (int i = 0; i < MAX; ++i)
		S_Push(p, numeros[i]);
}

void ImprimirPila(Pila_T *p) {
	printf("La cola es: \n");
	for (int i = 0; i < MAX; ++i)
		printf("%d ", S_Pop(p));
	puts("");
}

int main() {
	srand(time(NULL));
	Pila_T pila = Crear_Pila(MAX);
	Tipo_Dato *numeros = InitArr();
	CoparAPila(&pila, numeros);
	ImprimirPila(&pila);
	free(numeros);
	if ( Vaciar_Pila(&pila) ) {
		puts("La memoria ha sido vaciada.");
	}
}
