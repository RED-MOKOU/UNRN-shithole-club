/*10) Se tiene una pila de enteros positivos. Con las operaciones básicas de pilas y colas escribir un programa
para poner todos los elementos que son par de la pila en una cola. Luego, mostrar los elementos de la cola. NO
acceder a la estructura, usar funciones del TAD.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Tipo_Dato;
#include "pila_pointer.h"
#include "cola_pointer.h"
#define MAX 10

void InitStack(Pila_T *st) {
	for (int i = 1; i <= MAX; ++i)
		S_Push(st, i);
}

void ParseNumberes(Pila_T *s, Cola_T *q) {
	int temp, max = Longitud_Pila(*s);
	puts("La pila es:");
	for (int i = 0; i < max; ++i) {
		printf("%d ", temp = S_Pop(s));
		if ( temp % 2 == 0 )
			Q_Push(q, temp);
	}
	puts("");
}

void PrintQ(Cola_T *q) {
	int max = Longitud_Cola(*q);
	puts("La cola es:");
	for (int i = 0; i < max; ++i) {
		printf("%d ", Q_Pop(q));
	}
	puts("");
}

int main() {
	Pila_T numeros = Crear_Pila(MAX);
	InitStack(&numeros);
	Cola_T cola; Crear_Cola(&cola);
	ParseNumberes(&numeros, &cola);
	PrintQ(&cola);
	Vaciar_Pila(&numeros);
	Vaciar_Cola(&cola);
	return 0;
}
