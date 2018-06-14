#include "cola_pointer.h"

int Crear_Cola(Cola_T *cola) {
	cola->frente = NULL;
	cola->final = NULL;
	cola->size = 0;
	return 1;
}

int Q_Push(Cola_T *cola, Tipo_Dato x ) {
	tsNodo *new = NULL;
	if ( (new = (tsNodo*)malloc(sizeof(tsNodo))) == NULL ) {
		puts("Error: No hay memoria disponible.");
		return 0;
	}
	new->sig = NULL;
	new->dato = x;

	if ( cola->size <= 0) {
		cola->frente = new;
		cola->final = new;
	}
	else {
		cola->final->sig = new;
		cola->final = new;
	}
	++(cola->size);
	return 1;
}

Tipo_Dato Q_Pop(Cola_T *cola) {
	if ( cola->size > 0 ) {
		tsNodo *temp = cola->frente;
		Tipo_Dato temp_dato = temp->dato;
		cola->frente = temp->sig;
		free(temp);
		--(cola->size);
		return temp_dato;
	}
	else {
		puts("Error: La cola esta vacia.");
	}
}

int Cola_Vacia(Cola_T cola) {
	return ( cola.size == 0 ) ? 1 : 0;
}

Tipo_Dato Q_Top(Cola_T cola) {
	tsNodo *out = cola.frente;
	return out->dato;
}

int Longitud_Cola(Cola_T cola) {
	return cola.size;
}

int Vaciar_Cola(Cola_T *cola) {
	if ( cola->size > 0) {
		puts("Vaciando Cola.");
		tsNodo *temp = cola->frente;
		tsNodo *delete;
		for (int i = 0; i < cola->size; ++i) {
			delete = temp;
			temp = temp->sig;
			free(delete);
			printf(".");
		}
		printf("\n");
		return 1;
	}
	else
		return 0;
}

void MenuColaPointer(Cola_T *cola) {
	int op = 0;
	float elemento;
	do {
		puts("Que desea realizar?");
		puts("1)-Agregar dato (push)\n2)-Eliminar dato (pop)\n3)-Imprimir Tope de la cola\n0)-Salir\n");
		if(!scanf("%d", &op)) {
			puts("Error de input.");
			exit(-1);
		}
		switch(op) {
			case 0: break;
			case PUSH:
				puts("Ingrese el elemento que desea agregar:");
				if(!scanf("%f", &elemento)) {
					puts("Error de input.");
					exit(-1);
				};
				Tipo_Dato x = (Tipo_Dato)elemento;
				if(Q_Push(cola, x))
					printf("El dato %1.0f fue ingresado en la posicion %d\n", elemento, cola->size);
				break;
			case POP:
				printf("El dato eliminado es: %d\n", Q_Pop(cola));
				break;
			case PRINT:
				printf("El dato en el tope de la cola es: %d\n", Q_Top(*cola));
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}
