#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

/*Asigna valores aleatorios del 1 al 9 en un array[N]*/
int* InitArray() {

	int i;
	int* ar = malloc(sizeof(int)*N);
	int* cur = ar;
	for( i = 0; i < N; i++) {
		*cur = rand()%10;
		cur++;
	}
	return ar;
}

/*No sirve. Arreglar.*/
int* ShaveAr(int array[N], int num) {

	int arr2[N-1];
	int i,j = N+1;
	if (array[N] == num) {
		for( i = 0; i < N-1; i++)
			arr2[i] = array[i];
		return arr2;
	}
	if (array[N] != num) {
		for(i = 0; i < N-1; i++) {
			if( array[i] == num) {j = i; break;}
			arr2[i] = array[i];
		}
		if(j > N) break; 
		for (i = j; i < N-1; i++)
			arr2[i] = array[i+1];
		return arr2;
	}
	return array;
}

void PrintArray(int* array, int size) {

	int i;
	int* a = malloc(sizeof(int)*size);
	int* cur = a;
	for( i = 0; i < size; i++) 
		printf("%d ", array[i]);
	puts("");
	
}

int main(int argc, char** argv) {

	srand(time(NULL));
	int* ar = InitArray();
	int num;
	PrintArray(ar,N);
	puts("Ingrese un numero:");
	scanf("%d", &num);
	ar = ShaveAr(ar, num);
	PrintArray
	free(ar, (sizeof ar)/(sizeof(int)));
	return 0;
}
