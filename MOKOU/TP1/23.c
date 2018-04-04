/*23) Escribir y ejecutar un programa que mantenga informacion referente a coches en una ciudad. Solo se dispone
de matricula y de modelo (simplificar y asumir que ambos son números enteros). A partir de esta informacion,
generar 2 vectores: uno ordenado de forma creciente por matricula el otro ordenado de forma decreciente por modelo.
Mostrar los vectores resultantes. Utilizar el metodo de seleccion para realizar la ordenacion.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define MODEL 0
#define NUM 1

typedef struct {
	int mod, pat;
} tsMovil[SIZE];

void PrintAr(tsMovil n) {
	int i;
	for(i = 0; i < SIZE; i++) {
		if( (i%2 == 0) && (i != 0))
			puts("");
		printf("[Modelo: %d; Patente: %4d] ", n[i].mod, n[i].pat);
	}
	puts("");
}

void swap(int *x, int *y) {
	int aux = *x;
	*x = *y;
	*y = aux;
}

void InitAr(tsMovil a) {
	int i;
	for( i = 0; i < SIZE; i++) {
		a[i].mod = rand()%8; //8 modelos
		a[i].pat = rand()%5000+1000; //numero de patente entre 1000 y 6000
	}
}

void SelectionSort(tsMovil v, int flag) {
	int i, j, k, p, aux, limite = SIZE-1;
	for(k=0; k <  limite; k++) {
		p = k;
		switch(flag) {
			case MODEL:
				for (i = k + 1; i <= limite; i++) {
					if (v[i].mod > v[p].mod)
						p = i;
				}
				if (p != k) {
					swap(&v[p].mod, &v[k].mod);
					swap(&v[p].pat, &v[k].pat);
				}
				break;
			case NUM:
				for (i = k + 1; i <= limite; i++) {
					if (v[i].pat < v[p].pat)
						p = i;
				}
				if (p != k) {
					swap(&v[p].mod, &v[k].mod);
					swap(&v[p].pat, &v[k].pat);
				}
				break;
		}
	}
}

int main() {
	tsMovil arr;
	InitAr(arr);
	puts("Array:");
	PrintAr(arr);
	SelectionSort(arr, NUM);
	puts("Ordenado crecientemente por matricula:");
	PrintAr(arr);
	SelectionSort(arr, MODEL);
	puts("Ordenado decreciente por modelo:");
	PrintAr(arr);
	return 0;
}