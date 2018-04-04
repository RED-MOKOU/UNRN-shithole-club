/*4) Escriba y ejecute un programa que declare una matriz de enteros. Asuma una matriz cuadrada y varíe sus dimensiones.
Pruebe distintos valores como: 100, 500, 1000... hasta que dé un error en el momento de ejecución.
¿Por qué sucede esto?*/

/*Lim -> 10 000 (100 000 interos), luego de eso, el sistema se queja con un segmentation error (problema de alocacion de memoria).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500

void PrintMat(int m[N][N], int s) {
	int i,j;
	for( i = 0; i < s; i++) {
		for( j = 0; j < s; j++)
			printf("%2d ", m[i][j]);
		printf("\n");
	}
}

void InitMatrix(int mat[N][N], int size) {
	int i,j;
	
	for( i = 0; i < size; i++) {
		for( j = 0; j < size; j++) {
			mat[i][j] = rand()%100;
		}
	}
	PrintMat(mat, size);
}

int main(int argc, char** argv[])
{
	srand(time(NULL));
	int size, matriz[N][N];
	puts("Ingrese la dimension de la matriz:");
	scanf("%d", &size);
	if(size < 0) {
		printf("Error: Dimension invalida.");
		return 1;
	}
	InitMatrix(matriz, size);

	return 0;
}
