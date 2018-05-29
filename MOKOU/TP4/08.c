/*8) Implementar el TAD cola utilizando arreglos. Se puede utilizar la siguiente estructura:
#define Max 100
typedef struct
{
int frente;
int final;
Tipo_Dato Cola[Max]; // arreglo con los datos de la cola
}Cola_T;

1. int Crear_Cola(Cola_T *cola);
2. int S_Push(Cola_T *cola, Tipo_Dato x );
3. Tipo_Dato S_Pop(Cola_T *cola);
4. int Cola_Llena(Cola_T cola);
5. int Cola_Vacia(Cola_T cola);
6. Tipo_Dato S_Top(Cola_T cola);
7. int Longitud_Pila(Cola_T cola);
8. int Vaciar_Cola(cola_T *cola);
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define PUSH 1
#define POP 2
#define PRINT 3

typedef int Tipo_Dato;
typedef struct {
	int frente, final;
	Tipo_Dato *Cola;
} Cola_T;

/*Definidos por el ejercicio*/
int Crear_Cola(Cola_T *);
int S_Push(Cola_T*, Tipo_Dato );
Tipo_Dato S_Pop(Cola_T*);
int Cola_Llena(Cola_T);
int Cola_Vacia(Cola_T);
Tipo_Dato S_Top(Cola_T);
int Longitud_Pila(Cola_T);
int Vaciar_Cola(Cola_T*);

/*Definidos por el programador*/
void Quits();
void Menu(Cola_T*);

int main() {
	Cola_T cola;
	Crear_Cola(&cola);
	Menu(&cola);
	Vaciar_Cola(&cola);
	return 0;
}

void Quits() {
	puts("Error: No hay memoria disponible.");
	exit(-1);
}

// Crea la cola pasada como parámetro: con 0 elementos y asignando el valor correcto al resto de los campos.
int Crear_Cola(Cola_T *cola) {
	*cola = (Cola_T){ .frente = 0, .final = 0};
	if ( (cola->Cola = (Tipo_Dato*)malloc(MAX*sizeof(Tipo_Dato))) == NULL ) {
		puts("Error: No hay memoria disponible.");
		return 0;
	}
	return 1;
}

// Añade x a la cola, si la misma no está llena.
int S_Push(Cola_T *cola, Tipo_Dato x ) {
//	if ( cola->final < MAX ) {
	if (!Cola_Llena(*cola)) {
		cola->Cola[cola->final++] = x;
		return 1;
	}
	else {
		puts("Error: No puede incluirse el elemento a la cola (esta llena).");
		return 0;
	}
}

// Saca un elemento de la cola si la cola no está vacía. La función retorna dicho dato.
Tipo_Dato S_Pop(Cola_T *cola) {
//	if ( cola->frente > 0 ) {
	if (!Cola_Vacia(*cola)) {
		return cola->Cola[cola->frente++];
	}
	else
		puts("Error: No se puede retirar el elemento (la cola esta vacia).");
}

// Retorna True si la cola está llena. False caso contrario.
int Cola_Llena(Cola_T cola) {
	return (cola.frente == MAX) ? 1 : 0;
}

// retorna True si la cola está vacía. False caso contrario.
int Cola_Vacia(Cola_T cola) {
	return (Longitud_Pila(cola) == 0) ? 1 : 0;
}

// Retorna el dato que está en el tope de la cola, pero sin sacarlo (no modifica la cola)
Tipo_Dato S_Top(Cola_T cola) {
	return cola.Cola[cola.frente];
}

// Retorna la longitud de la cola.
int Longitud_Pila(Cola_T cola) {
	return (cola.final - cola.frente); // NOTA: En cola circular, verificar que la operacion no sea negativa.
}

// Vacia la cola pasada como parámetro.
int Vaciar_Cola(Cola_T *cola) {
	free(cola->Cola);
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
					printf("El dato %1f fue ingresado en la posicion %d\n", elemento, cola->final);
				break;
			case POP:
				printf("El dato eliminado es: %d\nEl frente esta en %d\n", S_Pop(cola), cola->frente);
				break;
			case PRINT:
				printf("El dato en el tope de la cola es: %d\n", S_Top(*cola));
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}
