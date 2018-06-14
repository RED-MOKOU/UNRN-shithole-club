#ifndef __TADLIST_H__
#define __TADLIST_H__
#define AGREGAR 1
#define ELIMINAR 2
#define IMPRIMIR 3
#define BUSCAR 4

#ifndef __NODO__
#define __NODO__
typedef struct Nodo {
	Tipo_Dato dato;
	struct Nodo *sig;
} tsNodo;
#endif

typedef struct {
	int n;
	tsNodo *lista;
} Lista_T;

//Crea una lista del tipo Lista_T con 0 elementos y la retorna (lista vacía).
Lista_T CrearLista();

//Inserta nodo con elemento x como primer elemento de la lista. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.
int InsertarPrimero(Lista_T*, Tipo_Dato);

//Inserta nodo con elemento x como último elemento de la lista. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.
int InsertarUltimo(Lista_T*, Tipo_Dato);

//Recorre la lista imprimiendo sus elementos. Retorna 1 si la operación se realiza con éxito, 0 caso contrario (la lista no tiene elementos).
int RecorrerLista(Lista_T);

//Retorna TRUE (1) si la lista está vacía, FALSE (0) caso contrario.
int EstaVacia(Lista_T);

//Desaloca la memoria de cada nodo. Longitud de la lista = 0. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.
int VaciarLista(Lista_T*);

//Elimina el nodo con el dato x de la lista. Retorna 1 si el dato esta en la lista (y es eliminado), 0 en caso contrario.
int SuprimirDato(Lista_T*, Tipo_Dato);

//Elimina el nodo con posición pos de la lista. Retorna 1 si el dato esta en la lista (y es eliminado), 0 en caso contrario.
int SuprimirNodo(Lista_T*, int);

//Retorna la longitud de la lista.
int LongitudLista(Lista_T);

//Devuelve el dato de la posición pos. Si no existe, devuelve una posicion negativa (-1)
int DevolverDatoPosicion(Lista_T, int);

//Menu en terminal para lista (tipo pointer)
void MenuLista(Lista_T*);

//Se hace apuntar l->lista al elemento siguiente al primero, y luego se libera este.
void SuprimirPrimerElemento(Lista_T*);

//Itera hasta el penultimo elemento, libera el ultimo y asigna NULL al que ahora es el ultimo elemento.
void SuprimirUltimoElemento(Lista_T*);

//Termina el programa e informa por print que no hay memoria
void Quits();

#endif
