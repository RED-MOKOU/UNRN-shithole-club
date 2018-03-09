#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void PrintArray(int*, int);

/*Asigna valores aleatorios del 1 al 9 en un array[N]*/
int* InitArray() {

	int i;
	int* arr = malloc(N * sizeof(int));
	printf("sizeof(int)*N = %d\n", (int)sizeof(int)*N);
	printf("**\nsizeof(arr) = %d\n**\n", (int)(sizeof arr));
	for( i = 0; i < N; i++)
		arr[i] = rand()%9+1;
	return arr;
}

int* ShaveAr(int array[N], int num) {

	int* arr2 = (int*)malloc(sizeof(int)*(N-1));
	int i, j = N+1;
	printf("Size of arr2 (top of the loop): %d\n", (int)(sizeof arr2));
	printf("--\nArray (top of the loop):\n");
	PrintArray(array,N);
	puts("--");

	if (array[N] == num) //if the last number in array is num (so we can use N-1 in the for loops)
	{
		for( i = 0; i < N-1; i++)
			arr2[i] = array[i];
		return arr2;
	}
	else
	{
		printf("--\nArray (first else)");
		PrintArray(array,N);
		puts("--");
		for(i = 0; i < N-1; i++) {
			if( array[i] == num) {j = i; break;}
			arr2[i] = array[i];
		}
		printf("j<N = %d<%d\n", j, N);
		printf("--\nArray (j<N):\n");
		PrintArray(array,N);
		puts("--");
		if(j < N) //if num is within range
		{
			for (i = j; i < N-1; i++)
				arr2[i] = array[i+1];
			puts("Return arr2");
//			PrintArray(arr2,(N-1));
			return arr2;
		}
		else
		{
			puts("Return array");
			PrintArray(array,N);
			puts("returned.");
			return array;
		}
	}
}

void PrintArray(int* array, int size) {

	int i;
	printf("print size: %d\n", size);
	for( i = 0; i < size; i++) 
		printf("%d ", array[i]);
	puts("");
	
}

int main(int argc, char** argv) {

	srand(time(NULL));
	int* ar = InitArray();
	printf("Size of ar (after init): %d (of %d)\n", (int)(sizeof ar), N);
	int num;
	PrintArray(ar,N);
	puts("Ingrese un numero:");
	scanf("%d", &num);
	ar = ShaveAr(ar, num);
	printf("Dimension of arnew: %d\n", (int)(sizeof ar));
	PrintArray(ar, (int)(sizeof ar +1));
	free(ar);
//	free(arnew);
	return 0;
}
