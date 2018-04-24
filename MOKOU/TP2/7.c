/*7) Se tiene un arreglo de n elementos enteros (n es ingresado por teclado y se aloca memoria de forma dinamica).
Se inicializa el vector con valores aleatorios entre 0 y VALOR_MAX. Se quiere generar otro arreglo
donde esten los elementos del vector original sin repetir. Escribir un programa que genere el nuevo vector, cuya
dimension solo se conoce en tiempo de ejecucion. Luego muestre en pantalla ambos vectores. Nota: no implementar
con un arreglo de N datos. Ir realocando en memoria dinamica espacio a medida que el vector resultado
va aumentando.
*/

#include "basiclib.h" //stdio, stdlib, time
#define MAX_VALUE 100

void PrintV(int* v, int dim) {
	for (int i = 0; i < dim; ++i)
		printf("%d ", v[i]);
	puts("");
}

int* InitV(int dim) {
	int *v = NULL;
	v = (int*)malloc(sizeof(*v)*dim);
	if(v == NULL) {
		puts("Error: Memoria insuficiente.");
		exit(1);
	}
	for (int i = 0; i < dim; i++)
		v[i] = rand()%MAX_VALUE;
	return v;
}

/*Retorna 0 si el valor num esta repetido en el vector v, 1 en caso contrario.*/
int IsInV(int *v, int pos, int dim, int num) {
	int i = 0, b = 1;
	while(i++ < dim) {
		if (num == v[i] && i != pos) {	//si el numero esta en el array y la comparacionn no se realiza
			b = 0;						//sobre la misma posicion que el elemento de referencia
			break;
		}
	}
	return b;
}

int* ProcessVec(int* vec, int dim, int* dimout) {
	int j = 0, *out = NULL;
	out = (int*)malloc(sizeof *out);
	if( out == NULL ) {
		puts("Error: Memoria insuficiente.");
		exit(1);
	}
	for(int i = 0; i < dim; ++i) {
		if( IsInV(vec, i, dim, vec[i]) ) {
			++(*dimout);
			out = (int*)realloc(out, (*dimout)*sizeof(int));
			out[j++] = vec[i];
		}
	}
	return out;
}

int main() {

	int *vec1, *vec2;
	int dim1 = 0, dim2 = 0;
	puts("Ingrese la dimension del vector:");
	scanf("%d", &dim1);
	if (dim1 < 1) {
		puts("Error: Dimension invalida.");
		exit(1);
	}
	vec1 = InitV(dim1);
	PrintV(vec1, dim1);
	vec2 = ProcessVec(vec1, dim1, &dim2);
	PrintV(vec2, dim2);
	free(vec1); 
	free(vec2);
	return 0;
}
