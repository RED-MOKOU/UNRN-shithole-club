/*7) Se desea formar una lista enlazada de números aleatorios. El programa que realiza esta tarea inserta los
nuevos nodos por la cabeza de la lista. Una vez creada la lista, se recorren los nodos para mostrar los números
pares. Implementar con funciones.
*/
#include <stdio.h>
#include <stdlib.h>
#include "TADlist.h"
#define MAX_VALUE 10

int main() {
	Lista_T Lista = CrearLista();
	int dim;
	puts("Ingrese el numero de elementos aleatorios que desea en la lista:");
	if(!scanf(" %c", &dim)) {
		puts("Error de input.");
		exit(-1);
	}
	if(InsertarPrimero(&Lista, rand()%MAX_VALUE)) {
		for(int i = 1; i < dim; ++i)
			InsertarUltimo(&Lista, rand()%MAX_VALUE);
	}
	RecorrerLista(Lista);
	if(VaciarLista(&Lista))
		printf("La lista ha sido vaciada.\n");
	else
		printf("La lista no tenia elementos para vaciar.\n");
	return 0;
}