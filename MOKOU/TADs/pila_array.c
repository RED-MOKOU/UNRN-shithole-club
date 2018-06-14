
#include "pila_array.h"

Pila_T Crear_Pila(int max) {
	return (Pila_T){ .indice = 0, .max = max, .pila = (Tipo_Dato*)malloc(max*sizeof(Tipo_Dato)) };
}

int Q_Push(Pila_T *pila, Tipo_Dato x ) {
	if(pila->max > pila->indice) {
		++(pila->indice);
		pila->pila[pila->indice] = x;
		return 1;
	}
	else {
		puts("Error: No se puede agregar el dato (la pila esta llena).");
		return 0;
	}
}

Tipo_Dato Q_Pop(Pila_T *pila) {
	if(pila->indice > 0) {
		--(pila->indice);
		return pila->pila[(pila->indice)+1];
	}
	else {
		puts("Error: La pila esta vacia.");
	}
}

int Pila_Llena(Pila_T pila) {
	return (pila.indice == pila.max) ? 1 : 0;
}

int Pila_Vacia(Pila_T pila) {
	return (pila.indice == 0) ? 1 : 0;
}

Tipo_Dato Q_Top(Pila_T pila) {
	return pila.pila[pila.indice];
}

int Longitud_Pila(Pila_T pila) {
	return pila.indice;
}

int Vaciar_Pila(Pila_T *pila){
		free(pila->pila);
}

Tipo_Dato *Sequence(Pila_T *q) {
	Tipo_Dato *array;
	if( (array = (Tipo_Dato*)malloc(MAX*sizeof(Tipo_Dato))) == NULL ) {
		puts("Error: Memoria insuficiente.");
		exit(-1);
	}
	for (int i = 0; i < MAX; ++i) {
		array[i] = seed+i;
		Q_Push(q, array[i]);
	}
	return array;
}

void PrintArr(int *arr) {
	printf("Array:|");
	for (int i = 0; i < MAX; ++i) printf("%3d|", arr[i]);
	puts("");
}

void PrintQueue(Pila_T *q) {
	printf("Queue:|");
	for (int i = 0; i < MAX; ++i) printf("%3d|", Q_Pop(q));
	puts("");
}

void MenuPilaArray(Pila_T *pila) {
	int op = 0, elemento;
	do {
		puts("Que desea realizar?");
		puts("1)-Agregar dato (push)\n2)-Eliminar dato (pop)\n3)-Imprimir Tope de Pila\n0)-Salir\n");
		if(!scanf("%d", &op)) {
			puts("Error de input.");
			exit(-1);
		}
		switch(op) {
			case 0: break;
			case PUSH:
				puts("Ingrese el elemento que desea agregar:");
				if(!scanf("%d", &elemento)) {
					puts("Error de input.");
					exit(-1);
				};
				Tipo_Dato x = (Tipo_Dato)elemento;
				if(Q_Push(pila, x))
					printf("El dato %d fue ingresado en la posicion %d\n", elemento, pila->indice);
				break;
			case POP:
				printf("El dato eliminado es: %d\n", Q_Pop(pila));
				break;
			case PRINT:
				printf("El dato en el tope de la pila es: %d\n", Q_Top(*pila));
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}
