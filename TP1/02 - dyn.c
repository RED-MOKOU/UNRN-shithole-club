/*2) Escriba y ejecute un programa que lea 2 enteros. Estos dos enteros definen las dimensiones de una matriz
(filas, columnas). La matriz tiene como dimensión física NxN, y dimensión lógica filasxcolumnas (enteros leídos).
El programa debe inicializar la matriz con valores aleatorios entre 20 y 30. Luego, se debe imprimir la
matriz de dos formas: por filas y por columnas. Definir funciones para inicializar y mostrar la matriz. Explique:
¿qué sucede si N es muy grande? ¿Qué sucede si N es muy pequeño?*/

/*Si N es muy grande no lo vas a poder mostrar por pantalla a menos que quieras que vaya nuclear,
si es muy pequeño, i.e. <0, no se puede definir una matriz con tamaño 0.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
     
int *InitArr(int row, int col) {
     
    signed int i, max = row*col;
    int* arr = malloc(sizeof(int)*max);
    int* cursor = arr;
    for( i = 0; i < max; i++ ) {  
        *cursor = rand()%11+20;
        cursor++;
    }
    return arr;
}
     
void Print(int* address, int row, int col) {

    int* p = address;
    signed int i, j;
    for( i = 0; i < row; i++ ) {
        for( j = 0; j < col; j++ )
            printf("%2d ", p[i*col+j]);
        printf("\n");
    }
}
     
int main(int argc, char** argv)
{
    srand(time(NULL));
    signed int a, b;
       
    puts("Ingrese dimensiones AxB");
    scanf("%d %d", &a, &b);
    if(a < 0 || b < 0) return 1; //don't do this please.
     
    int *matrix = InitArr(a, b);
    Print(matrix, a, b);
    free(matrix);
     
    return 0;
}
