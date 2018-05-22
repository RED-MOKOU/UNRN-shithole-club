/*1) Implementar el TAD Pila utilizando arreglos. Una posible implementación del tipo sería:

typedef struct {
	int indice; // tope de la pila
	Tipo_Dato pila[TamMax]; // pila
	int max; // máximo de la pila
} Pila_T;

El TAD debe disponer de las siguientes funciones:
1. int Crear_Pila(Pila_T *pila);
2. int Q_Push(Pila_T *pila, Tipo_Dato x );
3. Tipo_Dato Q_Pop(Pila_T *pila);
4. int Pila_Llena(Pila_T pila);
5. int Pila_Vacia(Pila_T pila);
6. Tipo_Dato Q_Top(Pila_T pila);
7. int Longitud_Pila(Pila_T pila);
8. int Vaciar_Pila(Pila_T *pila);
*/

#include <stdio.h>
#include <stdlib.h>
#define PUSH 1
#define POP 2
#define PRINT 3

typedef int Tipo_Dato;

typedef struct {
	int indice; // tope de la pila
	Tipo_Dato *pila; // pila
	int max;
} Pila_T;

/*Definidas por el ejercicio*/
Pila_T Crear_Pila(int);
int Q_Push(Pila_T*, Tipo_Dato);
Tipo_Dato Q_Pop(Pila_T*);
int Pila_Llena(Pila_T);
int Pila_Vacia(Pila_T);
Tipo_Dato Q_Top(Pila_T);
int Longitud_Pila(Pila_T);
int Vaciar_Pila(Pila_T*);

/*Definidas por el autor del codigo*/
void Menu(Pila_T*);

int main() {
	int max;
	puts("Ingrese el tamaño maximo de la pila:");
	if(!scanf("%d", &max)) {
		puts("Error: Input invalido.");
		exit(-1);
	}
	Pila_T pila = Crear_Pila(max);
	Menu(&pila);
	Vaciar_Pila(&pila);
	return 0;
}

//Crea la pila pasada como parámetro: con 0 elementos y asignando el valor correcto al resto de los
//campos. O esta función puede no recibir parámetros y devolver un dato de tipo Pila_T
Pila_T Crear_Pila(int max) {
	Pila_T out;
	out.indice = 0;
	out.max = max;
	out.pila = (Tipo_Dato*)malloc(max*sizeof(Tipo_Dato));
	return out;
}

//Añade x a la pila, si la misma no está llena.
//Retorna 1 si se agrega x con exito, 0 en caso contrario.
int Q_Push(Pila_T *pila, Tipo_Dato x ) {
	if(!Pila_Llena(*pila)) {
		++(pila->indice);
		pila->pila[pila->indice] = x;
		return 1;
	}
	else {
		puts("Error: No se puede agregar el dato (la pila esta llena).");
		return 0;
	}
}

//Saca un elemento de la pila si la pila no está vacía. La función retorna dicho dato.
Tipo_Dato Q_Pop(Pila_T *pila) {
	if(!Pila_Vacia(*pila)) {
		--(pila->indice);
		return pila->pila[(pila->indice)+1];
	}
	else {
		puts("Error: La pila esta vacia.");
	}
}

//Retorna True si la pila está llena. False caso contrario.
int Pila_Llena(Pila_T pila) {
	return (pila.indice == pila.max) ? 1 : 0;
}

//Retorna True si la pila está vacía. False caso contrario.
int Pila_Vacia(Pila_T pila) {
	return (pila.indice == 0) ? 1 : 0;
}

//Retorna el dato que está en el tope de la pila, pero sin sacarlo (no modifica la pila)
Tipo_Dato Q_Top(Pila_T pila) {
	return pila.pila[pila.indice];
}

//Retorna la longitud de la pila.
int Longitud_Pila(Pila_T pila) {
	return pila.indice;
}

//Vacia la pila pasada como parámetro.
int Vaciar_Pila(Pila_T *pila){
		free(pila->pila);
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
