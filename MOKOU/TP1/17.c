/*Un vector contiene los elementos mostrados a continuación. Los primeros dos elementos se han ordeado
utilizando un algoritmo de inserción. ¿Cuál será el valor de los elementos del vector después de tres pasadas
más del algoritmo?*/

//3 8 13 25 45 23 98 58

#include <stdio.h>
#define SIZE 8

void PrintVec(int vc[SIZE]) {
	int i;
	for( i = 0; i < SIZE; i++)
		printf("%d ", vc[i]);
	puts("");
}

void InsertionSort(int vector[SIZE]) {
	int i, j, aux;
	for(i = 1; i < SIZE; i++) {
		aux = vector[i];
		printf("aux=%d\n", aux);
		j = i - 1;
		while ((j >= 0) && (vector[j] > aux)) {
			vector[j+1] = vector[j];
			j--;
		}
		vector[j+1] = aux;
		printf("i: %d, vector: ", i);
		PrintVec(vector);
	}
}

int main() {
	int v[SIZE] = {3, 8, 13, 25, 45, 23, 98, 58};
	PrintVec(v);
	InsertionSort(v);
	return 0;
}