#ifndef __COLA_POINTER_H__
#define __COLA_POINTER_H__

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
	tsNodo *frente;
	tsNodo *final;
	int size;
} Cola_T;

/*---------------------------------
Definidas por el ejercicio
---------------------------------*/
// Crea la cola pasada como parámetro: con 0 elementos y asignando el valor correcto al resto de los campos (frente = final = NULL).
int Crear_Cola(Cola_T*);

// Añade x a la cola.
int Q_Push(Cola_T*, Tipo_Dato);

// Saca un elemento de la cola si la cola no está vacía. La función retorna dicho dato.
Tipo_Dato Q_Pop(Cola_T*);

// Retorna True si la cola está vacía. False caso contrario.
int Cola_Vacia(Cola_T);

// Retorna el dato que está en el tope de la cola, pero sin sacarlo (no modifica la cola)
Tipo_Dato Q_Top(Cola_T);

// Retorna la longitud de la cola.
int Longitud_Cola(Cola_T);

// Vacia la cola pasada como parámetro.
int Vaciar_Cola(Cola_T*);

/*---------------------------------
Definidas por el autor del codigo
---------------------------------*/
//Termina el programa e informa mediante un print de que no hay memoria disponible para alocar.
void Quits();

//Menu en terminal para cola (tipo pointer)
void MenuColaPointer(Cola_T*);

#endif
