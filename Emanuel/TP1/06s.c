/*6) Escribir y ejecutar un programa que inicialice un arreglo de N enteros y luego elimine la priner ocurrencia
de un número ingresado por parámetro. La eliminación debe ser tal que si el número no existe en el arreglo,
el arreglo queda de dimensión N. Si el elemento existe, el arreglo debe quedar de N-1 enteros y la eliminación
genera un corrimiento pisando el elemento eliminado: si se elimina el elemento de la posición 3, se debe mover
el ekenebti de posición 4 a la posición 3, el elemento de la posición 5 a la posición 4 y así sucesivamente,
reescribiendo las posiciones de los datos.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void PrintArr(int*, int);

/*Asigna valores aleatorios del 1 al 9 en el array*/
void InitArray(int array[N]) {
		int i;
		for (i = 0; i < N; i++)
			array[i] = rand()%9+1;
	PrintArr(array, N);
}

/*Confirma con un 1 si el numero esta dentro del array, y un 0 si no*/
int IsNum(int array[N], int num) {
		int i, result = 0;
		for (i = 0; i < N; i++) {
		if (array[i] == num) { result = 1; break; }
	}
	return result;
}

/*Si el numero esta en el array, lo elimina y mueve los elementos*/
void ShaveArr(int array[N], int num) {
	int i = 0, j = N+1, arr2[N-1];
	while( array[i] != num ) { //Asigna valores hasta encontrar a num
		arr2[i] = array[i];
		i++;
	}
	for( i; i < N-1; i++) { //Asigna valores luego de que num haya sigo encontrado
		arr2[i] = array[i+1];
	}
	for( i = 0; i < N-1; i++) { //Copia arr2 en array
		array[i] = arr2[i];
	}
}

/*Imprime el array*/
void PrintArr(int array[N], int size) {
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", array[i]);
	puts("");
}

int main( int argc, char** argv) {

	srand(time(NULL));
	int num = -1, arr[N];
	InitArray(arr);
	printf("Input number: "); scanf("%d",&num);
	if ( IsNum(arr, num) == 1 ) {
		ShaveArr(arr, num);
		PrintArr(arr, N-1);
	}
	else
		printf("\nEl numero ingresado no esta dentro del array.\n");
	return 0;
}
