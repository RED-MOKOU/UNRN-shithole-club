/*Jose Emanuel Suez - UNRN PyA

3) Escribir y ejecutar un programa que maneje números complejos (parte real e imaginaria asumirla como
enteros). Implemente funciones para: leer un número complejo, mostrar por pantalla un número complejo,
sumar 2 complejos, restar 2 números complejos y multiplicar dos números complejos.*/

#include <stdio.h>

typedef struct {
	int real;
	int img;
} tsCompNum;

tsCompNum Add(tsCompNum number1, tsCompNum number2) {
    
	tsCompNum result;
	result.real = number1.real + number2.real;
	result.img = number1.img + number2.img;
	return result;
}

tsCompNum Sub(tsCompNum number1, tsCompNum number2) {

	tsCompNum result;
	result.real = number1.real - number2.real;
	result.img = number1.img - number2.img;
	return result;
}

tsCompNum Mul(tsCompNum number1, tsCompNum number2) {

	tsCompNum result;
	result.real = (number1.real)*(number2.real) - (number1.img)*(number2.img);
	result.img = (number1.img)*(number2.real) + (number1.real)*(number2.img);
	return result;
}

void PrintNum(tsCompNum num) {printf("El resultado es: [%d,%di]",num.real,num.img);}

tsCompNum Leer() {
	tsCompNum r;
	puts("Ingrese numero complejo:");
	scanf("%d %d", &r.real, &r.img);
	return r;
}

int main() {

	tsCompNum num1, num2, result;
	char op;
	num1 = Leer();
	num2 = Leer();
	puts("Ingrese operador:");
	scanf(" %c", &op);

	switch(op) {
		case '+':
			result = Add(num1,num2);
			PrintNum(result);
			break;
		case '-':
			result = Sub(num1,num2);
			PrintNum(result);
			break;
		case '*':
			result = Mul(num1,num2);
			PrintNum(result);
			break;
		default: puts("Error: operador invalido.");
	}

	return 0;
}