/*6) Obtener una secuencia de 10 elementos reales, guardarlos en un array y ponerlos en una pila. Imprimir la
secuencia original y, a continuación, imprimir la pila extrayendo los elementos.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 10

typedef int Tipo_Dato;
Tipo_Dato seed;

typedef struct {
	int indice; // tope de la pila
	Tipo_Dato *pila; // pila
	int max;
} Pila_T;


//Crea la pila pasada como parámetro: con 0 elementos y asignando el valor correcto al resto de los
//campos. O esta función puede no recibir parámetros y devolver un dato de tipo Pila_T
Pila_T Crear_Pila(int max) {
	return (Pila_T){ .indice = 0, .max = max, .pila = (Tipo_Dato*)malloc(max*sizeof(Tipo_Dato)) };
}

//Añade x a la pila, si la misma no está llena.
//Retorna 1 si se agrega x con exito, 0 en caso contrario.
int Q_Push(Pila_T *pila, Tipo_Dato x ) {
	if(pila->max > pila->indice) {
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
	if(pila->indice > 0) {
		--(pila->indice);
		return pila->pila[(pila->indice)+1];
	}
	else {
		puts("Error: La pila esta vacia.");
	}
}

//Vacia la pila pasada como parámetro.
int Vaciar_Pila(Pila_T *pila){
		free(pila->pila);
}

Tipo_Dato *Sequence(Pila_T *q) {
	Tipo_Dato *array;
	if( (array = (Tipo_Dato*)malloc(MAX*sizeof(Tipo_Dato))) == NULL ) {
		puts("Error: Memoria insuficiente.");
		exit(-1);
	}
	for (int i = 0; i < MAX; ++i) {
		array[i] = seed+i;
		Q_Push(q, array[i]);
	}
	return array;
}

void PrintArr(int *arr) {
	printf("Array:|");
	for (int i = 0; i < MAX; ++i) printf("%3d|", arr[i]);
	puts("");
}

void PrintQueue(Pila_T *q) {
	printf("Queue:|");
	for (int i = 0; i < MAX; ++i) printf("%3d|", Q_Pop(q));
	puts("");
}

int main() {
	srand(time(NULL));
	seed = rand()%1000;
	Pila_T pila = Crear_Pila(MAX);
	Tipo_Dato *a = Sequence(&pila);

	printf("######|001|002|003|004|005|006|007|008|009|010|\n"); //posicion de elementos
	printf("------|---|---|---|---|---|---|---|---|---|---|\n");
	PrintArr(a);
	printf("------|---|---|---|---|---|---|---|---|---|---|\n");
	PrintQueue(&pila);
	printf("-----------------------------------------------\n");

	Vaciar_Pila(&pila);
	free(a);
	return 0;
}
