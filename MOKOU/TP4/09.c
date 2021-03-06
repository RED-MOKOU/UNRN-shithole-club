/*9) Implementar el TAD cola utilizando punteros. Se puede utilizar la siguiente estructura:

struct Nodo
{
Tipo_Dato dato;
struct Nodo *sig;
}
typedef struct
{
struct Nodo *frente;
struct Nodo *final;
int size;
}Cola_T;

1. int Crear_Cola(Cola_T *cola);
2. int S_Push(Cola_T *cola, Tipo_Dato x );
3. Tipo_Dato S_Pop(Cola_T *cola);
4. int Cola_Vacia(Cola_T cola);
5. Tipo_Dato S_Top(Cola_T cola);
6. int Longitud_Cola(Cola_T cola);
7. int Vaciar_Cola(Cola_T *cola);
*/

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
	tsNodo *frente;
	tsNodo *final;
	int size;
} Cola_T;

/*Definidos por el ejercicio*/
int Crear_Cola(Cola_T*);
int S_Push(Cola_T*, Tipo_Dato);
Tipo_Dato S_Pop(Cola_T*);
int Cola_Vacia(Cola_T);
Tipo_Dato S_Top(Cola_T);
int Longitud_Cola(Cola_T);
int Vaciar_Cola(Cola_T*);

/*Definidos por el programador*/
void Quits();
void Menu(Cola_T*);


int main() {
	Cola_T cola;
	Crear_Cola(&cola);
	Menu(&cola);
	if(Vaciar_Cola(&cola)) {
		puts("La cola ha sido vaciada.");
	}
	else
		puts("No habia elementos para vaciar.");
	return 0;
}

// Crea la cola pasada como parámetro: con 0 elementos y asignando el valor correcto al resto de los campos (frente = final = NULL).
int Crear_Cola(Cola_T *cola) {
	cola->frente = NULL;
	cola->final = NULL;
	cola->size = 0;
	return 1;
}

// Añade x a la cola.
int S_Push(Cola_T *cola, Tipo_Dato x ) {
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

// Saca un elemento de la cola si la cola no está vacía. La función retorna dicho dato.
Tipo_Dato S_Pop(Cola_T *cola) {
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

// Retorna True si la cola está vacía. False caso contrario.
int Cola_Vacia(Cola_T cola) {
	return ( cola.size == 0 ) ? 1 : 0;
}

// Retorna el dato que está en el tope de la cola, pero sin sacarlo (no modifica la cola)
Tipo_Dato S_Top(Cola_T cola) {
	tsNodo *out = cola.frente;
	return out->dato;
}

// Retorna la longitud de la cola.
int Longitud_Cola(Cola_T cola) {
	return cola.size;
}

// Vacia la cola pasada como parámetro.
int Vaciar_Cola(Cola_T *cola) {
	if ( cola->size > 0) {
		puts("Vaciando lista.");
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

void Menu(Cola_T *cola) {
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
				if(S_Push(cola, x))
					printf("El dato %1.0f fue ingresado en la posicion %d\n", elemento, cola->size);
				break;
			case POP:
				printf("El dato eliminado es: %d\n", S_Pop(cola));
				break;
			case PRINT:
				printf("El dato en el tope de la cola es: %d\n", S_Top(*cola));
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}
