#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 100

void GenArr(double array[N]) {

	signed int i;
	for( i = 0; i < N; i++ )
		array[i] = rand()%101+10;	//asign random values from 10 to 100, can be changed accordingly.
}

void PrintArr(double array[N]) {

	signed int i;
	for( i = 0; i < N; i++ )
		printf("%2d ", (int)array[i]);
	printf("\n");
}

int main(int argc, char** argv)
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
