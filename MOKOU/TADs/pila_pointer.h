#ifndef __PILA_POINTER_H__
#define __PILA_POINTER_H__

#ifndef __NODO__
#define __NODO__
typedef struct Nodo {
	Tipo_Dato dato;
	struct Nodo *sig;
} tsNodo;
#endif

#ifndef __OPCIONES__
#define __OPCIONES__
#define PUSH 1
#define POP 2
#define PRINT 3
#endif

typedef struct {
	int dim, max;
	tsNodo *sig;
} Pila_T;

/*---------------------------------
Definidas por el ejercicio
---------------------------------*/
//Crea la pila pasada como parámetro: con 0 elementos y asignando el valor correcto al resto de los
//campos. O esta función puede no recibir parámetros y devolver un dato de tipo Pila_T
Pila_T Crear_Pila(int);

//Añade x a la pila, si la misma no está llena.
//Retorna 1 si se agrega x con exito, 0 en caso contrario.
int S_Push(Pila_T*, Tipo_Dato);

//Saca un elemento de la pila si la pila no está vacía. La función retorna dicho dato.
Tipo_Dato S_Pop(Pila_T*);

//Retorna el dato que está en el tope de la pila, pero sin sacarlo (no modifica la pila)
Tipo_Dato S_Top(Pila_T);

//Vacia la pila pasada como parámetro.
int Vaciar_Pila(Pila_T*);

//Retorna True si la pila está llena. False caso contrario.
int Pila_Llena(Pila_T);

//Retorna True si la pila está vacía. False caso contrario.
int Pila_Vacia(Pila_T);

//Retorna la longitud de la pila.
int Longitud_Pila(Pila_T);

/*---------------------------------
Definidas por el autor del codigo
---------------------------------*/
//Menu en terminal para pila (tipo pointer)
void MenuPilaPointer(Pila_T*);

#endif
