#ifndef __ABB_H__
#define __ABB_H__
#define AGREGAR 1
#define ELIMINAR 2
#define IMPRIMIR 3

// typedef int Tipo_Dato; //tomo int como el tipo de dato por default

struct Nodo {
	Tipo_Dato dato;
	struct Nodo *izq;
	struct Nodo *der;
};

typedef struct Nodo *Arbol_T;

/* Crea un arbol con un nodo con x como dato. Hijo izq e hijo der son árboles vacíos (NULL) */
Arbol_T CrearArbol(Tipo_Dato x);

/* Inserta el elemento "dato" en el ABB */
int InsertarElemento(Arbol_T *a, Tipo_Dato dato);

/* Procesa el ABB a en orden */
void InOrder(Arbol_T a);

/* Procesa el ABB a con orden pre-orden */
void PreOrder(Arbol_T a);

/* Procesa el ABB a en orden post-orden */
void PostOrder(Arbol_T a);

/* elimina el elemento dato del ABB a */
void EliminarElemento(Arbol_T *a, Tipo_Dato dato);

/* Retorna true si el elemento dato existe en el ABB a */
int Existe(Arbol_T a, Tipo_Dato dato);

/* Retorna la cantidad de nodos del ABB a */
int ContarNodos(Arbol_T a);

/* Retorna el valor máximo del ABB a */
int Maximo(Arbol_T a);

/*Retorna en valor mínimo del ABB a */
int Minimo(Arbol_T a);

/* retorna la profundidad del ABB a */
int Profundidad(Arbol_T a);

/*---------------------------------
DEFINIDOS POR EL PROGRAMADOR
---------------------------------*/
void RecorrerArbol(Arbol_T a);
Arbol_T ValorMin(Arbol_T a);
void DestruirArbol(Arbol_T a);
void Menu();
void Quits();

#endif