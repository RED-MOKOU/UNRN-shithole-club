/* UNRN PyA - Jose Emanuel Suez

6) Escribir un programa que lea del teclado 2 valores que indican filas y columnas de una matriz (se aloca en
tiempo de ejecucion). Inicializar dicha matriz, y para cada fila de la matriz, indicar el valor maximo y el valor
minimo. Implementar con funciones.*/

#include "basiclib.h" //stdio, stdlib, time

int Min(int a, int b) { return a < b ? a : b; }
int Max(int a, int b) { return a > b ? a : b; }

void MinMax(int* v, int col, int row) {
	int i, j;
	for(i = 0; i < row; i++) {
		int max = 0;
		int min = 10;
		for (int j = 0; j < col; j++) {
			max = Max(max, v[i*col+j]);
			min = Min(min, v[i*col+j]);
		}
		printf("En la fila %d, el mayor es: %d y el menor es %d\n", i, max, min);
	}
}

void PrintV(int* vec, int c, int r) {
    int i, j;
	for(i = 0; i < r; i++) {
    	for(j = 0; j < c; j++)
			printf("%d ", vec[i*c+j]);
		printf("\n");
	}
}

int* InitMat(int cols, int rows) {
	int i, j, *b = NULL;
	b = (int*) malloc(sizeof(*b)*cols*rows);
	for(i = 0; i < cols; i++) {
		for(j = 0; j < rows; j++)
			b[i*cols+j] = rand()%10;
	}
	return b;
}

int main() {
	int r = 0, c = 0;
	int *v = NULL;
	puts("Ingrese las dimensiones de la matriz (aXb): ");
	scanf("%d %d", &c, &r);
	if( c < 0 || r < 0) {
		puts("Error: Dimension invalida.");
	    exit(-1);
	}
	v = InitMat(c, r);
	PrintV(v, c, r);
	MinMax(v, c, r);
	free(v);
	return 0;
}
