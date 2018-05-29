/*12) Escribir un programa en el que se generen 100 números aleatorios entre -25 y +25 y se guarden en una
cola. Una vez creada la cola, implementar una función que forme otra cola con los números negativos de la cola
original. NO acceder a la estructura, usar funciones del TAD.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Tipo_Dato;
#include "pila_pointer.h"
#include "cola_pointer.h"
#define MAX 100

void InitQueue(Cola_T *q) {
	for (int i = 0; i < MAX; ++i)
		Q_Push(q, rand()%50-25);
}
	
void CopiarNegativos(Cola_T *q, Cola_T *qn) {
	Tipo_Dato temp;
	for (int i = 1; i <= MAX; ++i) {
	    temp = Q_Pop(q);
	    printf("%d ", temp);
		if ( temp < 0 )
			Q_Push(qn, temp);
		if ( (i%10) == 0 )
		    printf("\n");
	}
	puts("");
}

void PrintQ(Cola_T *q) {
	int max = Longitud_Cola(*q);
	puts("La cola es:");
	for (int i = 1; i <= max; ++i) {
		printf("%d ", Q_Pop(q));
		if ( (i%10) == 0 )
		    printf("\n");
	}
	puts("");
}

int main() {
	srand(time(NULL));
	Cola_T cola, cola_negativos;
	Crear_Cola(&cola); Crear_Cola(&cola_negativos);
	InitQueue(&cola);
	CopiarNegativos(&cola, &cola_negativos);
	PrintQ(&cola_negativos);
	Vaciar_Cola(&cola); Vaciar_Cola(&cola_negativos);
	return 0;
}
