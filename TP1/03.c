#include <stdio.h>
#include <stdlib.h>

int* InitIdent(int size) {

	int* arr = (int*)malloc(sizeof(int)*size*size);
	int* cur = arr;
	signed int i,j;
	for( i = 0; i < size; i++) {
		for( j = 0; j < size; j++) {
			*cur = (i == j) ? 1 : 0;
			cur++;
		}
	}
	return arr;
}

void PrintMatrix(int* address, int size) {

	signed int i, j;
	int logicsize = size*size;
	int* p = address;

	printf("The memory userb for a matrix of %dx%d is: %d bytes\n", size, size,sizeof(int)*logicsize);
	for( i = 0; i < size; i++ ) {
		for( j = 0; j < size; j++ )
			printf("%1d ", p[i*size+j]);
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	int size;
	puts("Input matrix size:");
	scanf("%d", &size);
	int* matriz = InitIdent(size);
	PrintMatrix(matriz, size);
	free(matriz);
	return 0;
}
