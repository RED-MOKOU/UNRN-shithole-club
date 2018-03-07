/*Lim -> 10 000 (100 000 integers), after that, segmentation fault (i.e. ran out of memory on the block)*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* InitMatrix(int size) {

	signed int i,j;
	int* arr = (int*)malloc(sizeof(int)*size*size);
	int* cur = arr;
	
	for( i = 0; i < size; i++) {
		for( j = 0; j < size; j++) {
			*cur = rand()%100;
			cur++;
		}
	}
	return arr;
}

int main(int argc, char** argv[])
{
	srand(time(NULL));
	int size;
	puts("Ingrese la dimension de la matriz:");
	scanf("%d", &size); if(size < 0) return 1;
	int* matriz = InitMatrix(size);
//	printf("Size of matrix: %d bytes\n", sizeof(int)*size*size);
	free(matriz);

	return 0;
}
