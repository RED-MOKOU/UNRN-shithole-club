#include <stdio.h>
#include <stdlib.h> /* rand */
#define N 50

void
matrix_init(int matrix[N][N])
{
	/* why to use C99? it's 19 years old */
	int i;
	for (i = 0; i < N*N; i++)
		matrix[i/N][i%N] = rand() % 11 + 20;
}

void
matrix_show(const int matrix[N][N], int rows, int columns)
{
	int x, y;
	for (y = 0; y < rows && y < N; y++)
	{
		for (x = 0; x < columns && x < N; x++)
			printf("%d ", matrix[x][y]);
		printf("\n");
	}

}

int
main(int argc, char **argv)
{
	int matrix[N][N];
	matrix_init(matrix);

	int rows, columns;
	scanf("%d %d", &rows, &columns);
	/* avoid evil input */
	if (rows < 0 || columns < 0)
		return 1;
	matrix_show(matrix, rows, columns);

	return 0;
}

