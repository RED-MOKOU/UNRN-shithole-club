/*3) Escriba y ejecute un programa que lea un entero. Este entero define la dimensión lógica de una matriz cuadrada
(filas = columnas) de enteros. Escriba una función que inicialice una matriz identidad (matriz identidad:
m[i][j] = 1 si i = j, m[i][j] = 0 caso contrario). Escriba otra función que reciba la matriz y su dimensión lógica
e imprima sus valores. Asumir que la matriz es de N x N como máximo (dimensión física). Si N = 500, calcule
la cantidad de memoria que se reserva para la matriz y cuánto se usa realmente si se leen los valores: 10, 100,
50. Responda para cada valor: ¿cuántos bytes tienen datos válidos y cuántos no?*/

#include <stdio.h>
#include <stdlib.h>

int* InitIdent(int size) {

	int* arr = (int*)malloc(sizeof(int)*size*size);
	int* cur = arr;
	signed int i,j;
	for( i = 0; i < size; i++) {
		for( j = 0; j < size; j++) {
			*cur = (i == j) ? 1 : 0;
			cur++;
		}
	}
	return arr;
}

void PrintMatrix(int* address, int size) {
	signed int i, j;
	int logicsize = size*size;
	int* p = address;

	printf("La memoria ocupada por la matriz de %dx%d es: %d bytes\n", size, size,sizeof(int)*logicsize);
    for( i = 0; i < size; i++ ) {
        for( j = 0; j < size; j++ )
            printf("%1d ", p[i*size+j]);
        printf("\n");
    }
}

int main(int argc, char** argv)
{
	int size;
	puts("Ingrese dimension de la matriz:");
	scanf("%d", &size);
	int* matriz = InitIdent(size);
	PrintMatrix(matriz, size);
	free(matriz);
	return 0;
}
