#ifndef __ABB_H__
#define __ABB_H__

#ifndef __OPCIONES__
#define __OPCIONES__
#define AGREGAR 1
#define ELIMINAR 2
#define IMPRIMIR 3
#define INFO 4
#define BUSQUEDA 5
#endif

// typedef int Tipo_Dato; //tomo int como el tipo de dato por default

struct Nodo {
	Tipo_Dato dato;
	struct Nodo *izq;
	struct Nodo *der;
};

typedef struct Nodo *Arbol_T;

/* Crea un arbol con un nodo con x como dato. Hijo izq e hijo der son árboles vacíos (NULL) */
Arbol_T CrearArbol(Tipo_Dato);

/* Inserta el elemento "dato" en el ABB */
void InsertarElemento(Arbol_T*, Tipo_Dato);

/* Procesa el ABB a en orden */
void InOrder(Arbol_T);

/* Procesa el ABB a con orden pre-orden */
void PreOrder(Arbol_T);

/* Procesa el ABB a en orden post-orden */
void PostOrder(Arbol_T);

/* elimina el elemento dato del ABB a */
Arbol_T EliminarElemento(Arbol_T, Tipo_Dato);

/* Retorna true si el elemento dato existe en el ABB a */
int Existe(Arbol_T, Tipo_Dato);

/* Retorna la cantidad de nodos del ABB a */
int ContarNodos(Arbol_T);

/* Retorna el valor máximo del ABB a */
int Maximo(Arbol_T);

/*Retorna en valor mínimo del ABB a */
int Minimo(Arbol_T);

/* retorna la profundidad del ABB a */
int Profundidad(Arbol_T);

/*---------------------------------
DEFINIDOS POR EL PROGRAMADOR
---------------------------------*/
void RecorrerArbol(Arbol_T a);
Arbol_T ValorMin(Arbol_T);
void DestruirArbol(Arbol_T);
void Menu();
void Quits();

#endif
