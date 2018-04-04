/*7) Dado un arreglo de 1000 enteros, realizar una funcion que reciba dicho arreglo y un numero cualquiera
(ingresado por teclado). Dicha funcion debe informar si el entero se encuentra en el vector. Realizar esta funcion
de dos maneras distintas:
1. Recorriendo el vector de enteros en su totalidad.
2. Recorriendo hasta que encuentre el dato (o se termine el vector).
Conteste: ¿qué solucion cree que es mejor? ¿por qué? con la segunda opcion: ¿cuantas veces como mínimo
se comparan valores? ¿y como maximo? ¿y promedio?*/

/*La mejor solucion seria la primera, dado que utiliza menos recursos (solo compara hasta hallar el numero).
La segunda opcion, por otra parte, sigue recorriendo array hasta el final, haciendo el maximo de comparaciones (N).
El menor numero de comparaciones que podria darse seria 1, el cual podria darse al utilizar la segunda opcion y que el numero buscado
sea el primer dato comparado (la primera posicion del array).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

void InitArr(int arr[N]) {
	int i;
	for(i = 0; i < N; i++)
		arr[i] = rand()%100+1;
}

void Compare1(int arr[N], int num) {
	int i;
	for(i = 0; i < N; i++) {
		if(arr[i] == num)
			printf("\nEl numero \"%d\" se ha hallado en la posicion: %d", num, i);
	}
}

void Compare2(int arr[N], int num) {
	int i = 0;
	while (arr[i] != num) {
			i++;
		}
	printf("\nEl numero \"%d\" se ha hallado en la posicion: %d", num, i);
}

void PrintArr(int arr[N]) {
	int i;
	for(i = 0; i < N; i++) {
		printf("%3d ", arr[i]);
		if(i%30 == 0)
			printf("\n");
	}
	printf("\n---");
}

int main(int argc, char** argv) {

	srand(time(NULL));
	int arr[N], num, cho;
	InitArr(arr);
	PrintArr(arr);
	printf("Input number: ");
	scanf("%d", &num);
	printf("Que opcion desea realizar?\n1- Recorrer el vector en su totalidad?\n2- Recorrer el vector hasta hallar el numero? ");
	scanf("%d", &cho);
	switch(cho) {
		case 1: Compare1(arr, num); break;
		case 2: Compare2(arr, num); break;
		default: printf("Error: Operacion invalida.");
	}
	return 0;
}
