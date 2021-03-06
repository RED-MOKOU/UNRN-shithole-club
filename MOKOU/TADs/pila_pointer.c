#include "pila_pointer.h"

Pila_T Crear_Pila(int max) {
	return (Pila_T){ .dim = 0, .max = max, .sig = NULL };
}

int S_Push(Pila_T *pila, Tipo_Dato x ) {
	if(pila->dim < pila->max) {
		tsNodo *nuevo = NULL;	// Nodo a agregar
		if( (nuevo = (tsNodo*)malloc(sizeof(tsNodo))) == NULL ) {
			puts("Error: Memoria no disponible.");
			exit(-1);
		}
		nuevo->sig = NULL;
		nuevo->dato = x;
		if(pila->dim == 0)
			pila->sig = nuevo;
		else {
			tsNodo *temp = pila->sig;
			while(temp->sig != NULL)
				temp = temp->sig;	// Recorre la pila hasta el ultimo elemento
			temp->sig = nuevo;
		}
		++(pila->dim);
		return 1;
	}
	else {
		puts("Error: No se puede agregar el dato (la pila esta llena).");
		return 0;
	}
}

Tipo_Dato S_Pop(Pila_T *pila) {
	if(pila->dim > 0) {
		Tipo_Dato x;
		if(pila->dim > 1) {
			tsNodo *temp = pila->sig;
			while(temp->sig->sig != NULL)
				temp = temp->sig;		// Recorre la pila hasta el ante-ultimo elemento
			x = temp->sig->dato;
			free(temp->sig);
			temp->sig = NULL;

		}
		else { // Solo hay un elemento en la pila.
			x = pila->sig->dato;
			free(pila->sig);
			pila->sig = NULL;
		}
		--(pila->dim);
		return x;
	}
	else {
		puts("Error: La pila esta vacia.");
	}
}

Tipo_Dato S_Top(Pila_T pila) {
		if(pila.dim > 0) {
			tsNodo *temp = pila.sig;
			while(temp->sig != NULL)
				temp = temp->sig;	//recorre la pila hasta el ultimo elemento
			return temp->dato;
		}
		else
			puts("Error: No hay elementos en la pila.");
}

int Pila_Llena(Pila_T p) {
	return (p.dim == p.max) ? 1 : 0;
}

int Pila_Vacia(Pila_T p) {
	return (p.dim == 0) ? 1 : 0;
}
int Longitud_Pila(Pila_T p) {
	return p.dim;
}

int Vaciar_Pila(Pila_T *pila) {
	if(pila->dim > 0) {
		puts("Vaciando pila.");
		tsNodo *temp = pila->sig;
		tsNodo *old = NULL;
		for(int i = 0; i < pila->dim; ++i) {
			old = temp;
			temp = temp->sig;
			free(old);
		}
		free(temp);
		return 1;
	}
	else
		return 0;
}

void MenuPilaPointer(Pila_T *pila) {
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
				if(S_Push(pila, x)) {
					printf("El dato %d fue ingresado en la posicion %d\n", elemento, pila->dim);
					printf("La lista tiene ahora %d elementos.\n", pila->dim);
				}
				break;
			case POP:
				if(pila->dim > 0 )
					printf("El dato eliminado es: %d\n", S_Pop(pila));
				else
					puts("No hay datos en la pila.");
				break;
			case PRINT:
				if(pila->dim > 0)
					printf("El dato en el tope de la pila es: %d\n", S_Top(*pila));
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}
