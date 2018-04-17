/* UNRN PyA - Jose Emanuel Suez

9) Declare una estructura para representar un punto en el espacio tridimensional (con campos x,y,z). Declare
un puntero a la estructura para que tenga la direccion de un arreglo dinamico de n estructuras punto. Utilizar la
funcion calloc() para asignar memoria al arreglo y compruebe que se ha podido asignar la memoria requerida.
Escribir una funcion que retorne un puntero a un array de estructuras punto. Los valores de los puntos se
ingresan en esa funcion.*/

//#include "basiclib.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	float x, y, z;
} tsCoordinates;

void Quits() {
	puts("Error: Memoria insuficiente.");
	exit(-1);
}

void PrintV(tsCoordinates *v, int d) {
	for (int i = 0; i < d; ++i)
		printf("[%2.2f, %2.2f, %2.2f] ", (v++)->x, (v++)->y, (v++)->z);
}

tsCoordinates* Leer(int dim) {
	tsCoordinates *r = NULL;
	r = (tsCoordinates*)calloc(dim, sizeof *r);
	if(r == NULL)
		Quits();
	printf("Ingrese las coordenadas de los %d valores:\n", dim);
	for (int i = 0; i < dim; ++i)
		scanf("%f %f %f", &(r++)->x, &(r++)->y, &(r++)->z);
	return r;
}

int main() {
	tsCoordinates *p;
	int dim;
	puts("Ingrese dimension del array:");
	scanf("%d", &dim);
		p = Leer(dim);
	PrintV(p, dim);
	free(p);
	return 0;
}