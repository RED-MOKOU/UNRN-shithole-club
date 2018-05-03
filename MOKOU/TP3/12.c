/*12) Implementar el TAD lista circular con punteros. Una posible implementación del tipo sería:
struct NodoT {
	int dato;
	struct NodoT *sig;
};
typedef struct NodoT Nodo;
typedef struct{
	int n;
	Nodo *lista;
}ListaC_T;

El TAD debe disponer de las siguientes funciones:
1. ListaC_T CrearLista();
2. int InsertarDato(ListaC_T *l, int x );
3. int ImprimirLista(ListaC_T l);
4. int LongitudLista(ListaC_T l );*/

#include <stdio.h>
#include <stdlib.h>
#define AGREGAR 1
#define IMPRIMIR 2

typedef struct NodoT {
	int dato;
	struct NodoT *sig;
} tsNodo;

typedef struct{
	int n;
	tsNodo *lista;
} ListaC_T;

/*Definidos por el programador*/
void Menu(ListaC_T*);
int VaciarLista(ListaC_T*);
int EstaVacia(ListaC_T);

/*Definidos por la consigna del ejercicio*/
ListaC_T CrearLista();
int InsertarDato(ListaC_T *l, int x );
int ImprimirLista(ListaC_T l);
int LongitudLista(ListaC_T l );

int main() {
	ListaC_T lista = CrearLista();
	Menu(&lista);
	if(VaciarLista(&lista))
		printf("La lista ha sido vaciada.\n");
	else
		printf("La lista no tenia elementos para vaciar.\n");
	return 0;
}

/* crea una lista circular con 0 elementos y la retorna. */
ListaC_T CrearLista() {
	return (ListaC_T){.n = 0, .lista = NULL};
}

/*Retorna TRUE (1) si la lista está vacía, FALSE (0) caso contrario.*/
int EstaVacia(ListaC_T l) {
	return (l.n) ? 0 : 1;
}

/* inserta nodo con el elemento x al comienzo de la lista. Retorna 1 si la operación se realiza con éxito, -1 caso contrario. */
int InsertarDato(ListaC_T *l, int x ) {
	if(l->n != 0) {
		tsNodo *temp, *nuevo;
		if ((nuevo = (tsNodo*)malloc(sizeof(tsNodo))) == NULL) {
			puts("No hay memoria disponible para alocar el nodo.");
			return 0;
		} 
		nuevo->dato = x;
		nuevo->sig = l->lista;
		if (!EstaVacia(*l)) {
			temp = l->lista;
			do {
				temp = temp->sig;
			} while (temp->sig != l->lista);
			temp->sig = nuevo;
		}
		++(l->n);
		return 1;
	}
	else {
		tsNodo *nuevo = NULL;
		if((nuevo = (tsNodo*)malloc(sizeof(tsNodo))) == NULL) {
			return -1;
		}
		l->lista = nuevo;
		nuevo->dato = x;
		nuevo->sig = l->lista;
		++(l->n);
		return 1;
	}

}

/* imprime la lista, sin importar desde donde. */
int ImprimirLista(ListaC_T l) {
	tsNodo *elemento;
	if(l.n < 0)
		return 0;
	else  {
		elemento = l.lista; // n apunta al primer elemento de la lista
		puts("");
		do {
			printf("%d ",elemento->dato);
			elemento = elemento->sig;
		} while(elemento != l.lista);
	}
	printf("\n\n");
	return 1;
}

/* Retorna la longitud de la lista l */
int LongitudLista(ListaC_T l ) {
	return l.n;
}

/*Desaloca la memoria de cada nodo. Longitud de la lista = 0. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.*/
int VaciarLista(ListaC_T *l) {
	tsNodo *head, *curr;
	printf("Vaciando lista");
	if(l->n > 0) {
		head = l->lista;
		for (int i = 0; i < l->n; ++i) {
			head = head->sig;
			free(curr);
			printf(".");
		}
		puts("");
		l->n = 0;
		return 1;
	}
	else
		return 0;
}

void Menu(ListaC_T *list) {
	int op = 0, num;
	do {
		puts("Que desea realizar?");
		puts("1)-Agregar dato\n2)-Imprimir lista\n0)-Salir\n");
		if(!scanf("%d", &op)) {
			puts("Error de input.");
			exit(-1);
		}
		switch(op) {
			case 0: break;
			case AGREGAR:
				puts("Ingrese el numero que desea agregar:");
				if(!scanf("%d", &num)) {
					puts("Error de input.");
					exit(-1);
				};
				if(InsertarDato(list, num) == 1)
					printf("El dato %d fue agregado\n", num);
				else
					puts("Error: No se pudo agregar el dato.");
				break;
			case IMPRIMIR:
				if(ImprimirLista(*list) != 1)
					puts("La lista esta vacia.");
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}