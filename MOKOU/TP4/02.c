/*
2) Implementar el TAD Pila utilizando punteros. Se piden las mismas operaciones para que en el punto 1. Si
alguna operación no tiene sentido justificar. Una posible implementación del tipo sería:

struct Nodo {
	Tipo_Dato dato;
	struct Nodo *sig;
}
typedef struct {
	int dim; // cantidad de datos de la pila
	struct Nodo *pila; // puntero a la pila
} Pila_T;
*/

/*Las funciones relacionadas a la dimension de la pila estan de mas, dado que el valor que estas retornan esta en el elemento "dim" en el tipo Pila_T.*/

#include <stdio.h>
#include <stdlib.h>
#define PUSH 1
#define POP 2
#define PRINT 3

typedef int Tipo_Dato;

typedef struct Nodo {
	Tipo_Dato dato;
	struct Nodo *sig;
} tsNodo;

typedef struct {
	int dim, max;
	tsNodo *sig;
} Pila_T;

/*Definidas por el ejercicio*/
Pila_T Crear_Pila(int);
int Q_Push(Pila_T*, Tipo_Dato);
Tipo_Dato Q_Pop(Pila_T*);
Tipo_Dato Q_Top(Pila_T);
int Vaciar_Pila(Pila_T*);
//int Pila_Llena(Pila_T);
//int Pila_Vacia(Pila_T);
//int Longitud_Pila(Pila_T);


/*Definidas por el autor del codigo*/
void Menu(Pila_T*);

int main() {
	int max;
	puts("Ingrese el tamaño maximo de la pila:");
	if(!scanf("%d", &max)) {
		puts("Error: Input invalido.");
		exit(-1);
	}
	Pila_T Pila = Crear_Pila(max);
	Menu(&Pila);
	if(Vaciar_Pila(&Pila))
		puts("La pila ha sido vaciada con exito.");
	else
		puts("La lista no tenia elementos para vaciar.");
	return 0;
}

//Crea la pila pasada como parámetro: con 0 elementos y asignando el valor correcto al resto de los
//campos. O esta función puede no recibir parámetros y devolver un dato de tipo Pila_T
Pila_T Crear_Pila(int max) {
	return (Pila_T){ .dim = 0, .max = max, .sig = NULL };
}

//Añade x a la pila, si la misma no está llena.
//Retorna 1 si se agrega x con exito, 0 en caso contrario.
int Q_Push(Pila_T *pila, Tipo_Dato x ) {
	if(pila->dim != pila->max) {
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

//Saca un elemento de la pila si la pila no está vacía. La función retorna dicho dato.
Tipo_Dato Q_Pop(Pila_T *pila) {
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

//Retorna el dato que está en el tope de la pila, pero sin sacarlo (no modifica la pila)
Tipo_Dato Q_Top(Pila_T pila) {
		if(pila.dim > 0) {
			tsNodo *temp = pila.sig;
			while(temp->sig != NULL)
				temp = temp->sig;	//recorre la pila hasta el ultimo elemento
			return temp->dato;
		}
		else
			puts("Error: No hay elementos en la pila.");
}

//Vacia la pila pasada como parámetro.
int Vaciar_Pila(Pila_T *pila) {
	if(pila->dim > 0) {
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

void Menu(Pila_T *pila) {
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
				if(Q_Push(pila, x)) {
					printf("El dato %d fue ingresado en la posicion %d\n", elemento, pila->dim);
					printf("La lista tiene ahora %d elementos.\n", pila->dim);
				}
				break;
			case POP:
				if(pila->dim > 0 )
					printf("El dato eliminado es: %d\n", Q_Pop(pila));
				else
					puts("No hay datos en la pila.");
				break;
			case PRINT:
				if(pila->dim > 0)
					printf("El dato en el tope de la pila es: %d\n", Q_Top(*pila));
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}
