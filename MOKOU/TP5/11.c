#include <stdio.h>
#include <stdlib.h>
typedef int Tipo_Dato;
#include "ABB.c"

int main() {
	Arbol_T arbol = NULL;
	Menu(arbol);
	puts("Destuyendo el arbol...");
	DestruirArbol(arbol);
	puts("El arbol ha sido destruido.");
	return 0;
}
