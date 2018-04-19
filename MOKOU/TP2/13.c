/* UNRN PyA - Jose Emanuel Suez

13) Calculadora: Implementar una calculadora que sepa sumar, restar, multiplicar y dividir 2 numeros flotantes.
Mostrar un menu con las 4 opciones, y utilizando puntero a funcion, realizar la operacion solicitada y
mostrar el resultado.*/

#include <stdio.h>
#define SUMA 1
#define RESTA 2
#define MULTIPLICAR 3
#define DIVIDIR 4

float Suma(float a, float b) {
	return a+b;
}

float Resta(float a, float b) {
	return a-b;
}

float Multiplicar(float a, float b) {
	return a*b;
}

float Dividir(float a, float b) {
	return a/b;
}

int main() {
	float a = 0, b = 0, (*Operacion)(float,float) = NULL;
	int op = 0;
	char op_sym = 0;
	puts("Ingrese los valores con los que desea operar:");
	scanf("%f %f", &a, &b);
	printf("Que operacion desea realizar?\n1)-Suma\n2)-Resta\n3)-Multiplicacion\n4)-Division\n");
	scanf("%d", &op);
	switch(op) {
		case SUMA:
			Operacion = Suma;
			op_sym = '+';
			break;
		case RESTA:
			Operacion = Resta;
			op_sym = '-';
			break;
		case MULTIPLICAR:
			Operacion = Multiplicar;
			op_sym = '*';
			break;
		case DIVIDIR:
			Operacion = Dividir;
			op_sym = '/';
			break;
		default: puts("Error: Operacion invalida."); exit(1);
	}
	printf("%2.2f%c%2.2f = %2.2f", a, op_sym, b, Operacion(a, b));
	return 0;
}