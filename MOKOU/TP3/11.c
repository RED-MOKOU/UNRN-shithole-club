/*11) Implementar el TAD lista doblemente enlazada de enteros utilizando punteros. Una posible implementación
del tipo sería:
UNRN

typedef struct NodoDE {
	int dato;
	struct NodoDE *sig;
	struct NodoDE *ant;
} tsNodo;

typedef struct {
	int n;
	tsNodo *primero;
	tsNodo *ultimo;
} ListaDE_T;

El TAD debe disponer de las siguientes funciones:
1. ListaDE_T crearLista();
2. int InsertarPrimero(ListaDE_T *l, int x );
3. int InsertarUltimo(ListaDE_T *l, int x );
4. int RecorrerListaEnOrden(ListaDE_T l );
5. int RecorrerListaEnOrdenInverso(ListaDE_T l);
6. int EstaVacia(ListaDE_T l);
7. int SuprimirDato(ListaDE_T *l, int x);
8. int VaciarLista(ListaDE_T *l);
9. int LongitudLista(ListaDE_T l);
10. int DevolverDatoPosicion(ListaDE_T l, int pos);
*/
#include <stdio.h>
#include <stdlib.h>
#define AGREGAR 1
#define ELIMINAR 2
#define IMPRIMIR 3
#define BUSCAR 4

typedef struct NodoDE {
	int dato;
	struct NodoDE *sig;
	struct NodoDE *ant;
} tsNodo;

typedef struct {
	int n;
	tsNodo *primero;
	tsNodo *ultimo;
} ListaDE_T;

/*Definidos por el programador*/
void Menu(ListaDE_T*);
void SuprimirPrimerElemento(ListaDE_T*);
void SuprimirUltimoElemento(ListaDE_T*);
void Quits();

/*Definidos por la consigna del ejercicio*/
ListaDE_T crearLista();
int InsertarPrimero(ListaDE_T *l, int x );
int InsertarUltimo(ListaDE_T *l, int x );
int RecorrerListaEnOrden(ListaDE_T l );
int RecorrerListaEnOrdenInverso(ListaDE_T l);
int EstaVacia(ListaDE_T l);
int SuprimirDato(ListaDE_T *l, int x);
int VaciarLista(ListaDE_T *l);
int LongitudLista(ListaDE_T l);
int DevolverDatoPosicion(ListaDE_T l, int pos);

int main() {
	ListaDE_T lista = crearLista();
	Menu(&lista);
	if(VaciarLista(&lista))
		printf("La lista ha sido vaciada.\n");
	else
		printf("La lista no tenia elementos para vaciar.\n");
	return 0;
}
/*crea una lista del tipo ListaDE_T con 0 elementos y la retorna.*/
ListaDE_T crearLista() {
	return (ListaDE_T){ .n = 0, .primero=NULL, .ultimo=NULL};
}

// inserta nodo con elemento x como primer elemento de la lista. Retorna 1 si la operación se realiza con éxito, -1 caso contrario.
int InsertarPrimero(ListaDE_T *l, int x ) {
	tsNodo *nuevo = NULL;
	if((nuevo = (tsNodo*)malloc(sizeof(tsNodo))) == NULL) {
		return -1;
	}
	nuevo->dato = x;
	nuevo->sig = nuevo->ant = NULL;
	l->primero = nuevo;
	l->ultimo = nuevo;
	++(l->n);
	return 1;
}

/*inserta nodo con elemento x como último elemento de la lista. Retorna 1 si la operación se realiza con éxito, -1 caso contrario.*/
int InsertarUltimo(ListaDE_T *l, int x ) {
	tsNodo *temp, *nuevo;
	if ((nuevo = (tsNodo*)malloc(sizeof(tsNodo))) == NULL) {
		puts("No hay memoria disponible para alocar el nodo.");
		return -1;
	} 
	nuevo->dato = x;
	nuevo->sig = NULL; //ultimo elemento en la lista
	if (!EstaVacia(*l)) {
		temp = l->primero;
		while (temp->sig != NULL)
			temp = temp->sig;
		temp->sig = nuevo;
		nuevo->ant = temp;
		nuevo->sig = NULL;
		l->ultimo = nuevo;
	}
	++(l->n);
	return 1;
}

/*Recorre la lista l imprimiendo sus elementos, del primer elemento al último. Retorna 1 si la operación se realiza con éxito, -1 caso contrario.*/
int RecorrerListaEnOrden(ListaDE_T l) {
	tsNodo *elemento;
	if(l.n < 0)
		return 0;
	else  {
		elemento = l.primero; // n apunta al primer elemento de la lista
		puts("");
		while (elemento != NULL) {
			printf("%d ", elemento->dato);
			elemento = elemento->sig;
		}
	}
	printf("\n\n");
	return 1;
}

/*Recorre la lista l imprimiendo sus elementos, del último elemento al primero. Retorna 1 si la operación se realiza con éxito, -1 caso contrario.*/
int RecorrerListaEnOrdenInverso(ListaDE_T l) {
	tsNodo *elemento;
	if(l.n < 0)
		return -1;
	else  {
		elemento = l.ultimo; // n apunta al último elemento de la lista
		puts("");
		while (elemento != NULL) {
			printf("%d ",elemento->dato);
			elemento = elemento->ant;
		}
	}
	printf("\n\n");
	return 1;
}

/*retorna True (1) si la lista está vacía, False (0) caso contrario.*/
int EstaVacia(ListaDE_T l) {
	return (l.n) ? 0 : 1;
}

/* Elimina el nodo con el dato x de la lista.*/
int SuprimirDato(ListaDE_T *l, int x) {
	tsNodo *curr, *temp = NULL;
	int pos = 0;
	if(l->n) {
		if ((l->primero)->dato == x) { //Primer elemento
			SuprimirPrimerElemento(l);
			--(l->n);
			return 1;
		}
		curr = l->primero;
		while ((curr->sig)->dato != x) {
			curr = curr->sig;
			++pos;
		}
		if(pos == (l->n)-1) { //ultimo elemento
			SuprimirUltimoElemento(l);
			--(l->n);
			return 1;
		}
		else if ((curr->sig)->dato == x) {
			temp = curr->sig;
			curr->sig = temp->sig;
			free(temp);
			--(l->n);
			return 1;
		}
		else
			return 0;
	}
}

/* desaloca la memoria de cada nodo. Longitud de la lista = 0.*/
int VaciarLista(ListaDE_T *l) {
	tsNodo *head, *curr;
	printf("Vaciando lista");
	if(l->n > 0) {
		head = l->primero;
		while ((curr = head) != NULL) {
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

/* retorna la longitud de la lista*/
int LongitudLista(ListaDE_T l) {
	return l.n;
}

/* devuelve el dato de la posición pos.*/
int DevolverDatoPosicion(ListaDE_T l, int pos) {
	tsNodo *act;
	if (pos >= 1 && pos <= LongitudLista(l)) {
		if(pos <= l.n>>1) {
			act = l.primero;
			for (int i = 0; i < pos; ++i)
				act = act->sig;
			return (act->dato);
		}
		else {
			act = l.ultimo;
			for (int i = 0; i < (l.n-pos); ++i)
				act = act->ant;
			return (act->dato);
		}
	}
	else {
		printf("Posicion fuera de rango.\n");
		return -1;
	}
}

/*Se hace apuntar l->primero al elemento siguiente al primero, y luego se libera este.*/
void SuprimirPrimerElemento(ListaDE_T* l) {
    tsNodo *temp;
	if((temp = l->primero) == NULL) {
		puts("Error: No se puede eliminar datos (no hay primer elemento).");
		return;
	}
	l->primero = (l->primero)->sig;
	l->primero->ant = NULL;
	free(temp);
}

/*Itera hasta el penultimo elemento, libera el ultimo y asigna NULL al que ahora es el ultimo elemento.*/
void SuprimirUltimoElemento(ListaDE_T *l) {
	l->ultimo->ant->sig = NULL;
	free(l->ultimo);
}

void Menu(ListaDE_T *list) {
	int op = 0, primero = 1, result, num, bus_op;
	char charop;
	do {
		puts("Que desea realizar?");
		puts("1)-Agregar dato\n2)-Eliminar dato\n3)-Imprimir lista\n4)-Buscar dato\n0)-Salir\n");
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
				if(!primero)
					result = InsertarUltimo(list, num);
				else {
					primero = 0;
					result = InsertarPrimero(list, num);
				}
				if(result)
					printf("El dato %d fue agregado en la posicion %d\n", num, list->n);
				else
					puts("Error: No se pudo agregar el dato.");
				break;
			case ELIMINAR:
					puts("Ingrese el dato que desea eliminar:");
					if(!scanf("%d", &num)) {
						puts("Error de input.");
						exit(-1);
					}
					if(SuprimirDato(list, num))
						printf("Dato \"%d\" eliminado.\n", num);
					else
						puts("El dato ingresado no existe en la lista.");
				break;
			case IMPRIMIR:
				printf("a).Orden comun\nb).Orden inverso\n");
				if(!scanf(" %c", &charop)) {
					puts("Error de input.");
					exit(-1);
				}
				if(charop == 'a' || charop == 'A') {
					if(RecorrerListaEnOrden(*list) != 1)
						puts("La lista esta vacia.");
				}
				else if(charop == 'b' || charop == 'B') {
					if(RecorrerListaEnOrdenInverso(*list) != 1)
						puts("La lista esta vacia.");
				}
				break;
			case BUSCAR:
				puts("Ingrese la posicion del dato:");
				if(!scanf("%d", &bus_op)) {
					puts("Error de input.");
					exit(-1);
				}
				num = DevolverDatoPosicion(*list, bus_op);
				if(num != -1)
					printf("El numero de la posicion \"%d\" es: %d\n", bus_op, num);
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}
