/*24) Se tienen 2 vectores A y B, ambos de 20 enteros. Se pide ordenar ambos vectores de forma creciente y
luego, generar un vector C de 40 enteros que sea el “merge” de dichos vectores A y B. La operacion de merge
consiste en intercalar los datos de los vectores A y B de forma ordenada en el vector C: cada dato insertado
en C es el minimo entre A y B (y se avanza en el vector donde se encontraba el minimo). Utilizar el método
shellsort para realizar la ordenacion de los vectores A y B. Mostrar el vector C ordenado.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void swap(int *x, int *y) {
	int aux = *x;
	*x = *y;
	*y = aux;
}

void InitAr(int r[SIZE]) {
	int i;
	for (int i = 0; i < SIZE; ++i)
		r[i] = rand()%30+20;
}

void PrintAr(int r[SIZE]) {
	int i;
	for (int i = 0; i < SIZE; ++i) {
		if( (i%10 == 0) && (i != 0))
			printf("\n");
		printf("%2d ", r[i]);
	}
	printf("\n\n");
}

void ShellSort(int vector[SIZE]) {
	int i, j,aux, incr = SIZE;
	do {
		for (i = incr; i < SIZE; i++) {
			for (j = i; (j>=incr) && (vector[j-incr]>vector[j]); j -= incr)
				swap(&vector[j], &vector[j-incr]);
		}
		incr = incr >> 1; //Division mas rapida
	} while (incr >0);
}

void Merge(int A[SIZE], int B[SIZE], int C[SIZE*2]) {
	int i = 0, j = 0, k = 0;
	while (k < SIZE*2) {
		printf("[i,j,k] = [%d,%d,%d]\nA[i] = %d, B[j] = %d\n", i, j, k, A[i], B[j]);
		if( A[i] < B[j] && (i < SIZE)) {
			C[k] = A[i];
			i++; k++;
		}
		else {
			if(j < SIZE) {
			C[k] = B[j]++;
			j++; k++;
			}
		}
		printf("C[k] = %d\n", C[k-1]);
	}
	
}

int main() {
	
	int a[SIZE], b[SIZE], c[SIZE*2];
	InitAr(a); InitAr(b);
	ShellSort(a); ShellSort(b);
	PrintAr(a); PrintAr(b);
	Merge(a, b, c);
	int i;
	for (int i = 0; i < SIZE*2; ++i) {
		if( (i%10 == 0) && (i != 0))
			printf("\n");
		printf("%2d ", c[i]);
	}
	return 0;
}
