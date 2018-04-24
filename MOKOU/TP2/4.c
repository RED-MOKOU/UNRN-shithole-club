/*4) Realizar un programa que lea un valor del teclado. Alocar en memoria dinámica un vector de enteros de
longitud igual al valor leído. Inicializar dicho vector con valores aleatorios entre 10 y 20. Imprimir el vector.
Implementar usando funciones.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MemQuit(int num) {
	puts("Error: Memoria insuficiente.");
	exit(i);
}

int LeerLon() {
	int l;
	puts("Ingrese longitud del array:");
	scanf("%d", &l);
	if( lon <= 0 ) {
		puts("Error: Longitud invalida.");
		exit(1);
	}
	return l;
}

int *InitArr(int size) {
	int i, *v = NULL;
	*v = (int*) malloc(sizeof(int)*size);
	if( v == NULL) { MemQuit(1); }
	for(i = 0; i < size; i++)
		v[i] = rand()%10+10;
	return v;
}

void PrintArr(int *vec, int size) {
	int i;
	for(i = 0; i < size; i++)
		printf("%d ", vec[i]);
	printf("\n");
}

int main() {
	srand(time(NULL));
	int lon = LeerLon();
	int *vec = InitArr(lon);
	PrintArr(vec, lon);
	free(vec);
	return 0;
}
