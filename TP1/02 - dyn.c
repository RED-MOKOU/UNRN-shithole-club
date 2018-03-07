/*2) Escriba y ejecute un programa que lea 2 enteros. Estos dos enteros definen las dimensiones de una matriz
(filas, columnas). La matriz tiene como dimensión física NxN, y dimensión lógica filasxcolumnas (enteros leídos).
El programa debe inicializar la matriz con valores aleatorios entre 20 y 30. Luego, se debe imprimir la
matriz de dos formas: por filas y por columnas. Definir funciones para inicializar y mostrar la matriz. Explique:
¿qué sucede si N es muy grande? ¿Qué sucede si N es muy pequeño?*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FillArr(int address, int row, int col) {

	signed int i, j;
	int** arr = (int**)malloc(sizeof(int)*row*col);
	arr = address;
	for( i = 0; i < row; i++ ) {    //ERROR CODE 139 SEGMENTATION FAULT
		for( j = 0; j < col; j++ ) {
			arr[i][j] = rand()%11+20;
			printf("%2d", arr[i][j]);
			}
	}
	free(arr);
}

void Print(int** address, int row, int col) {

//	int rows = sizeof array / sizeof array[0];
// 	int cols = sizeof array[0] / sizeof(int);

	int** p = address;
	signed int i, j;
	for( i = 0; i < row; i++ ) {
		for( j = 0; j < col; j++ )
			printf("%2d ", p[i][j]);
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	signed int a, b;
	
	puts("Ingrese dimensiones AxB");
	scanf("%d %d", &a, &b);
	int array[a][b];
	FillArr(&array, a, b);
	Print(array, a, b);

	return 0;
}
