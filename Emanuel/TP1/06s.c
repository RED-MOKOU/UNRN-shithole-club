#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

void PrintArr(int*, int);

/*Assigns random values from 1 to 9 and inits the array*/
void InitArray(int array[N]) {
        int i;
        for (i = 0; i < N; i++)
                array[i] = rand()%9+1;
	PrintArr(array, N);
}

/*Checks whether num is inside array and returns 1 if true*/
int IsNum(int array[N], int num) {

        int i, result = 0;
        for (i = 0; i < N; i++) {
		if (array[i] == num) { result = 1; break; }
	}
	return result;
}

//If num is within array, shaves num off the array
void ShaveArr(int array[N], int num) {
	int i = 0, j = N+1, arr2[N-1];
	while( array[i] != num ) { //assigns values until num is found
		arr2[i] = array[i];
		i++;
	}
	for( i; i < N-1; i++) { //assigns values after num is found
		arr2[i] = array[i+1];
	}
	for( i = 0; i < N-1; i++) { //copies arr2 to array
		array[i] = arr2[i];
	}
}

/*I wonder what's this for???*/
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
                printf("\nError: Number isn't inside array.\n"); //AKA nothing fucking happens.

        return 0;
}
