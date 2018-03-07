/*1) ¿Cuánto ocupará un arreglo de enteros de 100 elementos? ¿Y un arreglo de doubles de 100 elementos?
Escriba y ejecute un programa que inicialice con valores aleatorios ambos arreglos, los muestre por pantalla
y por último muestre la cantidad de bytes que ocupa cada uno. Implemente con funciones. Utilice la función
sizeof() cuando sea necesario.*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100

void GenArr(double array[N]) {

	signed int i;
	for( i = 0; i < N; i++ )
		array[i] = rand()%10;	//asign random values from 0 to 10, can be changed accordingly.
}

void PrintArr(double array[N]) {

	signed int i;
	for( i = 0; i < N; i++ )
		printf("%2.2f ", array[i]);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int a1[N];
	double a2[N];
	
	printf("Size of an int array of 100 numbers: %d bytes\n", (int)sizeof(a1));
	printf("Size of a double array of 100 numbers: %d bytes\n", (int)sizeof(a2));

	GenArr((double*)a1);
	GenArr(a2);
	PrintArr((double*)a1);
	PrintArr(a2);
	return 0;
}
