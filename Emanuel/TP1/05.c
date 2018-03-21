/*5) Escriba y ejecute un programa que mantenga información de números complejos (usando el tipo de datos
definido en el trabajo práctico 0). Se desea tener 2 matrices de complejos (de 10 filas por 10 columnas) y realizar
la suma y resta de dichas matrices. Implemente con funciones.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

typedef struct {
	int real, imag;
} tsComplex[N][N];

//Podria mejorarse para que imprima 0 cuando la parte real e imaginaria son 0, o solo la parte real si la imaginaria es 0,
//Pero no es el objetivo del trabajo.
void PrintNum(tsComplex number) {
	int i, j, aux;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			if(number[i][j].imag < 0 ) {
				aux = number[i][j].imag*(-1);
				printf("%d-%di ", number[i][j].real, aux);
			}
			else {
				printf("%d+%di ", number[i][j].real, number[i][j].imag);
			}
		}
	printf("\n");
	}
	printf("\n");
}

void InitNum(tsComplex num) {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			num[i][j].real = rand()%18-9;
			num[i][j].imag = rand()%18-9;
		}
	}
}

void Add(tsComplex result, tsComplex number1, tsComplex number2) {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			result[i][j].real = number1[i][j].real + number2[i][j].real;
			result[i][j].imag = number1[i][j].imag + number2[i][j].imag;
		}
	}
}

void Sub(tsComplex result, tsComplex number1, tsComplex number2) {
	int i, j;
	for(i = 0; i < N; i++) {
		for(j = 0; j < N; j++) {
			result[i][j].real = number1[i][j].real - number2[i][j].real;
			result[i][j].imag = number1[i][j].imag - number2[i][j].imag;
		}
	}	
}

int main(int argc, char** argv) {

	srand(time(NULL));
	tsComplex num1, num2, result;
	char operator;
	InitNum(num1); InitNum(num2);
	PrintNum(num1); PrintNum(num2);
	puts("Que operacion desea realizar? (+, -)");
	scanf(" %c", &operator);
	if (operator != '+' && operator != '-' ) {
		printf("Error: Operacion Invalida.");
		return -1;
	}
	switch(operator) {
		case '+': Add(result, num1, num2); break;
		case '-': Sub(result, num1, num2); break;
	}
	PrintNum(result);
	return 0;
}
