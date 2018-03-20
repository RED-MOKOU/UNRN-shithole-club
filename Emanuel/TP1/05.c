#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

typedef struct {
	int real, imag;
} tsComplex[N][N];

/*Usage; PrintNum(&var_add)*/
void PrintNum(tsComplex *number) {

	int i, j, aux;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if( number[i][j]->imag < 0 ) {
				aux = number[i][j]->imag*(-1);
				printf("%d-%di ", number[i][j]->real, aux);
			}
			else {
				printf("%d+%di ", number[i][j]->real, number[i][j]->imag);
			}
		}
	printf("\n");
	}
	printf("\n");
}

/*Usage: InitNum(&var_add)*/
void InitNum(tsComplex *num) {
	int i, j;
	for (i = 0; i < N; i++) {
		for( j = 0; j < N; j++) {
			num[i][j]->real = rand()%20-10;
			num[i][j]->imag = rand()%20-10;
		}
	}
}

tsComplex *Add(tsComplex *number1, tsComplex *number2) {
	tsComplex *result;
	int i, j;
//	puts("---");
	for( i = 0; i < N; i++) {
		for( j = 0; j < N; j++) {
			result[i][j]->real = number1[i][j]->real + number2[i][j]->real;
//			printf("r[%d][%d]:%d+%d=%d ", i , j, number1[i][j]->real, number2[i][j]->real, result[i][j]->real);
			result[i][j]->imag = number1[i][j]->imag + number2[i][j]->imag;
//			printf("i[%d][%d]:%d+%d=%d ", i , j, number1[i][j]->imag, number2[i][j]->imag, result[i][j]->imag);
		}
//		printf("\n");
	}
//	puts("---");
	return result;
}

tsComplex *Sub(tsComplex *number1, tsComplex *number2) {
	tsComplex *result;
	int i, j;
	for( i = 0; i < N; i++) {
		for( j = 0; j < N; j++) {
			result[i][j]->real = number1[i][j]->real - number2[i][j]->real;
			result[i][j]->imag = number1[i][j]->imag - number2[i][j]->imag;
		}
	}	
	return result;
}

int main(int argc, char** argv) {

	srand(time(NULL));
	tsComplex num1, num2, *result;
	char operator;
	InitNum(&num1);
	InitNum(&num2);
	PrintNum(&num1);
	PrintNum(&num2);
	puts("What would you like to do? (+, -)");
	scanf(" %c", &operator);
	if ((operator != '+' && operator != '-' )) {
		printf("Error: Invalid Operation.");
		return -1;
	}
	switch(operator) {
		case '+': result = Add(&num1, &num2); break;
		case '-': result = Sub(&num1, &num2); break;
	}
	PrintNum(result);
	return 0;
}
