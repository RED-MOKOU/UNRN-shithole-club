/*2) Escriba y ejecute un programa que lea 2 enteros. Estos dos enteros definen las dimensiones de una matriz
(filas, columnas). La matriz tiene como dimensión física NxN, y dimensión lógica filasxcolumnas (enteros leídos).
El programa debe inicializar la matriz con valores aleatorios entre 20 y 30. Luego, se debe imprimir la
matriz de dos formas: por filas y por columnas. Definir funciones para inicializar y mostrar la matriz. Explique:
¿qué sucede si N es muy grande? ¿Qué sucede si N es muy pequeño?*/

/*Si N es muy grande, se aloca memoria extra que luego el usuario no usara (por lo que se desperdician recursos).
Por el contrario, si N es muy pequeño, la memoria alocada no alcanzara para almacenar todos los datos de la matriz.*/

#include <stdio.h>
#include <stdlib.h> //para el uso de rand()
#include <time.h> //para la seed de rand
#define N 100 //Se asume que la matriz no sera mayor que 100x100. Preferentemente, habria que usar memoria dinamica.
	 
void InitArr(int mat[N][N], int row, int col) {
	 int i, j;
	for( i = 0; i < row; i++ ) {  
		for( j = 0; j < col; j++)
			mat[i][j] = rand()%10+20;
	}
}
	 
void Print(int mat[N][N], int row, int col) {
	int i, j;
	for( i = 0; i < row; i++ ) {
		for( j = 0; j < col; j++ )
			printf("%2d ", mat[i][j]);
		printf("\n");
	}
}
	 
int main(int argc, char** argv)
{
	srand(time(NULL));
	signed int a, b, matrix[N][N];  
	puts("Ingrese dimensiones AxB");
	scanf("%d %d", &a, &b);
	if(a < 0 || b < 0) {
		printf("Error: Dimension invalida."); //la version correcta seria fprintf(stderr,"Error: Dimension invalida"), pero no tiene para este ejemplo.
		return 1;
	}
	InitArr(matrix, a, b);
	Print(matrix, a, b);
	 
	return 0;
}
