/*15) Escribir una función para crear una copia de una cola determinada. La función tendrá dos argumentos, el
primero es la cola origen y el segundo la cola que va a ser la copia. Las operaciones que se han de utilizar serán
únicamente las definidas para el tipo cola. En esta función no se acceden a las estructuras del tipo, solo se deben
invocar funciones del TAD.
*/

#include "cola_pointer.h"

/*Copia cola1 en cola2*/
void CopiarCola(Cola_T *cola1, Cola_T *cola2) {
	int len = Longitud_Cola(cola1); // Asumo que las dos colas tienen el mismo tamaño (definidas previamente fuera de la funcion)
	for (int i = 0; i < len; ++i) {
		Q_Push(cola2, Q_Pop(cola1));
	}
}
