#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InitArr(int** matrix, int row, int col) {

	signed int i, max = row*col;
	int** arr = (int**)malloc(sizeof(int)*max);
	arr = matrix;
	for( i = 0; i < max; i++ ) {  
		**arr = rand()%11+20;
		arr++;
	}
	free(arr);
}

void Print(int** address, int row, int col) {

/*Compute size of array through this*/
//	int rows = sizeof array / sizeof array[0];
// 	int cols = sizeof array[0] / sizeof(int);

	int** p = address;
	signed int i, j;
	for( i = 0; i < row; i++ ) {
		for( j = 0; j < col; j++ )
			printf("%2d ", p[i][j]);
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	srand(time(NULL));
	signed int a, b;
	
	puts("Ingrese dimensiones AxB");
	scanf("%d %d", &a, &b);
	if(a < 0 || b < 0) return 1; //don't do this please.

	int array[a][b];
	InitArr(array, a, b);
	Print(array, a, b);

	return 0;
}
