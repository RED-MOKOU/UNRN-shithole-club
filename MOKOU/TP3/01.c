/*1) Implementar el TAD lista de enteros utilizando punteros. Una posible implementación del tipo sería:
struct Nodo
{
	int dato;
	struct Nodo *sig;
};

typedef struct
{
	int n;
	struct Nodo *lista;
} Lista_T;

El TAD debe disponer de las siguientes funciones:
Lista_T crearLista();
int InsertarPrimero(Lista_T *l, int x );
int InsertarUltimo(Lista_T *l, int x );
int RecorrerLista(Lista_T l );
int EstaVacia(Lista_T l);
int VaciarLista(Lista_T *l);
int SuprimirDato(Lista_T *l, int x);
int SuprimirNodo(Lista_T *l, int pos);
int LongitudLista(Lista_T l);
int DevolverDatoPosicion(Lista_T l, int pos);
*/
#include <stdio.h>
#include <stdlib.h>
#define AGREGAR 1
#define ELIMINAR 2
#define IMPRIMIR 3
#define BUSCAR 4

struct Nodo {
	int dato;
	struct Nodo *sig;
};

typedef struct {
	int n;
	struct Nodo *lista;
} Lista_T;

/*Definidos por el programador*/
void Menu(Lista_T*);
void SuprimirPrimerElemento(Lista_T*);
void Quits();

/*Definidos por la consigna del ejercicio*/
Lista_T CrearLista();
int InsertarPrimero(Lista_T*, int);
int InsertarUltimo(Lista_T*, int);
int RecorrerLista(Lista_T);
int EstaVacia(Lista_T);
int VaciarLista(Lista_T*);
int SuprimirDato(Lista_T*, int);
int SuprimirNodo(Lista_T*, int);
int LongitudLista(Lista_T);
int DevolverDatoPosicion(Lista_T, int);

int main() {
	Lista_T LinkedList;
	LinkedList = CrearLista();
	Menu(&LinkedList);
	VaciarLista(&LinkedList);
	return 0;
}

/*Crea una lista del tipo Lista_T con 0 elementos y la retorna (lista vacía).*/
Lista_T CrearLista() {
	Lista_T l;
	l = (Lista_T){.n = 0, .lista = NULL};
	return l;
}

/*Inserta nodo con elemento x como primer elemento de la lista. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.*/
int InsertarPrimero(Lista_T *l, int x) {
	struct Nodo *nuevo = NULL;
	if((nuevo = (struct Nodo*)malloc(sizeof(struct Nodo))) == NULL) {
		Quits();
	}
	nuevo->dato = x;
	nuevo->sig = NULL;
	l->lista = nuevo;
	++(l->n);
	return 1;
}

/*Inserta nodo con elemento x como último elemento de la lista. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.*/
int InsertarUltimo(Lista_T *l, int x ) {
	struct Nodo *p, *nuevo;
	if ((nuevo = (struct Nodo*)malloc(sizeof(struct Nodo))) == NULL) {
		printf("No hay memoria disponible.\n");
		return 0;
	} 
	nuevo->dato = x;
	nuevo->sig = NULL; //ultimo elemento en la lista
	if (!EstaVacia(*l)) {
		p = l->lista;
		while (p->sig != NULL)
			p = p->sig;
		p->sig = nuevo; //p esta en el ultimo nodo, se actualiza su campo siguiente para que apunte a "nuevo"
	}
	++(l->n);
	return 1;
}

/*Recorre la lista “l” imprimiendo sus elementos. Retorna 1 si la operación se realiza con éxito, 0 caso contrario (la lista no tiene elementos).*/
int RecorrerLista(Lista_T l) {
	struct Nodo *Elemento;
	if(l.n < 0)
		return 0;
	else  {
		Elemento = l.lista; // n apunta al primer elemento de la lista
		puts("");
		while (Elemento != NULL) {
			printf("%d ",Elemento->dato);
			Elemento = Elemento->sig;
		}
	}
	printf("\n\n");
	return 1;
}

/*Retorna TRUE (1) si la lista está vacía, FALSE (0) caso contrario.*/
int EstaVacia(Lista_T l) {
	return (l.n) ? 0 : 1;
}

/*Desaloca la memoria de cada nodo. Longitud de la lista = 0. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.*/
//Nota: Cuando no se realiza con exito?
int VaciarLista(Lista_T *l) {
	struct Nodo *head, *curr;
	printf("Vaciando lista...");
	if(l->n < 0) {
		head = l->lista;
		while ((curr = head) != NULL) {
			head = head->sig;
			free(curr);
		}
	l->n = 0;
	}
	printf(" la lista ha sido vaciada.");
	return 1;
}

/*Elimina el nodo con el dato x de la lista. Retorna 1 si el dato esta en la lista (y es eliminado), 0 en caso contrario.*/
int SuprimirDato(Lista_T *l, int x) {
	struct Nodo *curr, *temp = NULL;
	int pos = 0;
	if(l->n) {
		curr = l->lista;
		while ((curr->sig)->dato != x) {
			curr = curr->sig;
			++pos;
			}
		if (!pos)
			SuprimirPrimerElemento(l);
		else {
			temp = curr->sig;
			curr->sig = temp->sig;
			free(temp);
			return 1;
		}
	}
}

/*Elimina el nodo con posición pos de la lista. Retorna 1 si el dato esta en la lista (y es eliminado), 0 en caso contrario.*/
int SuprimirNodo(Lista_T *l, int pos) {
	struct Nodo *curr = l->lista;
	struct Nodo *temp = NULL;
	if(pos == 0)
		SuprimirPrimerElemento(l);
	for (int i = 0; i < --pos; ++i) {
		if(curr->sig == NULL)
			return 0;
		curr = curr->sig;
	}
	temp = curr->sig;
	curr->sig = temp->sig;
	free(temp);
	return 1;
}

/*Retorna la longitud de la lista.*/
int LongitudLista(Lista_T l) {
	return l.n;
}

/*Devuelve el dato de la posición pos. Si no existe, devuelve una posicion negativa (-1)*/
int DevolverDatoPosicion(Lista_T l, int pos) {
	struct Nodo *act;
	if (pos >= 1 && pos <= LongitudLista(l)) {
		act = l.lista;
		for (int i = 0; i < pos; ++i)
			act = act->sig;
		return (act->dato);
	}
	else {
		printf("Posicion fuera de rango.\n");
		return -1;
	}
}

void SuprimirPrimerElemento(Lista_T* l) {
	struct Nodo *temp = NULL;
	if(l->lista == NULL) {
		puts("Error: No se puede eliminar datos (no hay primer elemento.)");
		return;
	}
	temp = l->lista;
	l->lista = (l->lista)->sig;
	free(temp);
}

void Quits() {
	puts("Error: Memoria insuficiente.");
	exit(1);
}

void Menu(Lista_T *list) {
	int op = 0, primero = 1, result, num, bus_op;
	char op_elim;
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
				printf("a).Por dato\nb).Por posicion\n");
				if(!scanf(" %c", &op_elim)) {
					puts("Error de input.");
					exit(-1);
				}
				if(op_elim == 'a' || op_elim == 'A') {
					puts("Ingrese el dato que desea eliminar:");
					if(!scanf("%d", &num)) {
						puts("Error de input.");
						exit(-1);
					}
					if(SuprimirDato(list, num))
						printf("Dato \"%d\" eliminado.\n", num);
					else
						puts("El dato ingresado no existe en la lista.");
				}
				else if(op_elim == 'b' || op_elim == 'b') {
					puts("Ingrese la posicion del nodo que desea eliminar:");
					if(!scanf("%d", &num)){
						puts("Error de input.");
						exit(-1);
					}
					if(SuprimirNodo(list, num))
						printf("El nodo en la posicion %d ha sido eliminado.\n", num);
					else
						puts("Posicion invalida.");
				}
				break;
			case IMPRIMIR:
				if(RecorrerLista(*list) != 1)
					puts("La lista esta vacia.");
				break;
			case BUSCAR:
				puts("Ingrese la posicion del dato:");
				if(!scanf("%d", &bus_op)) {
					puts("Error de input.");
					exit(-1);
				}
				num = DevolverDatoPosicion(*list, bus_op);
				if(num != -1)
					printf("El numero de la posicion \"%d\" es: %d\n", num, bus_op);
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}
