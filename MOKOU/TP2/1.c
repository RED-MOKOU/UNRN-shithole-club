/*1) Se pide escribir un programa que mantenga la informacion de 10 numeros complejos. El siguiente codigo
muestra una solucion propuesta. Explique que hace. Esquematice graficamente las estructuras de datos usadas
y las variables. Ejemplifique entradas y salidas. ¿Es correcta dicha propuesta para solucionar el problema? Implementar
las funcines leerComplejo() y mostrarComplejo().*/

/*El programa crea un pointer a array de dimension DIM del tipo Complex_T (numeros complejos con parte real e imaginaria como ints),
un pointer de tipo Complex_T, y un numero imaginario. Le pide al usuario que ingrese los valores de un numero imaginario, los cuales
son alojados en num1. A su vez, se le asigna a cada elemento dentro del array la direccion de este valor "num1".
Luego, se imprime el vector completo.
El problema es que en este programa, todas las direcciones dentro del array *vector[DIM] son exactamente las mismas. Todos los
elementos de este vector son, en realidad, num1, el cual toma solo el ultimo valor ingresado por el usuario. Por lo tanto,
no es una solucion correcta.*/

#include <stdio.h>
#define DIM 3

typedef struct {
	int real, imag;
} Complex_T;

Complex_T leerComplejo(); // lee los campos de un complejo y lo retorna
int mostrarComplejo(Complex_T num_c); // muestra los campos del complejo num_c

int main() {
	Complex_T *vector[DIM];
	Complex_T *p_num;
	int i;
	Complex_T num1;

	// inicializacion del vector de complejos
	for(i=0; i <DIM; i++) {
		num1 = leerComplejo();
		vector[i] = &num1;
	}

	// impresion del vector de complejos
	for(i=0; i <DIM; i++) {
		p_num = vector[i];
		mostrarComplejo(*p_num);
	}
	return 0;
}

/*Implementacion de las funciones prototipo*/
Complex_T leerComplejo() {
	Complex_T a;
	puts("Ingrese valor real e imaginario del numero:");
	scanf("%d %d", &a.real, &a.imag);
	return a;
}

int mostrarComplejo(Complex_T num_C) {
	printf("[%d,%di] ", num_C.real, num_C.imag);
}
