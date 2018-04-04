/*21) Escribir y ejecutar un programa que ordene un vector de 50 enteros. Primero se debe mostrar los datos en
orden creciente y luego en orden decreciente. Utilizar el metodo Burbuja.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 0
#define DOWN 1
#define SIZE 50

void swap(int *x, int *y) {
	int aux = *x;
	*x = *y;
	*y = aux;
}

void PrintArr(int a[SIZE]) {
	int i;
	for( i = 0; i < SIZE; i++){
		if( (i%10 == 0) && (i != 0))
			printf("\n");
		printf("%2d ", a[i]);
	}
	puts("");
}

void InitArr(int a[SIZE]) {
	int i;
	for( i = 0; i < SIZE; i++)
		a[i] = rand()%100;
}

void BubbleSort(int vector[SIZE], int flag) {
	int i, j, aux;
	for(i=0; i < SIZE; i++) {
		for(j=i+1; j < SIZE; j++) {
			switch(flag) {
				case UP:
					if (vector[j] < vector[i])
						swap(&vector[i], &vector[j]);
					break;
				case DOWN:
					if (vector[j] > vector[i])
						swap(&vector[i], &vector[j]);
					break;
			}
		}
	}
}

int main() {
	srand(time(NULL));
	int arr[SIZE] = {0};
	InitArr(arr);
	puts("Array:");
	PrintArr(arr);
	puts("Creciente:");
	BubbleSort(arr, UP); PrintArr(arr);
	puts("Decreciente:");
	BubbleSort(arr, DOWN); PrintArr(arr);
	return 0;
}