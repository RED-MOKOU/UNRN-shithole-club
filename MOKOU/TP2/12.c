/* UNRN PyA - Jose Emanuel Suez

12) Retomar los algoritmos de ordenacion vistos anteriormente e implementar un programa donde se le pida
al usuario que algoritmo quiere utilizar: (1) Metodo de la burbuja, (2) Metodo de Insercion, (3) Metodo de Seleccion,
(4) Shell Sort. Declarar un puntero a una funcion que ordene un vector de enteros de dimension DIM.
Elegir en tiempo de ejecucion el metodo de ordenacion e invocarlo utilizando un puntero a funcion. Tomar
tiempos utilizando las funciones clock() de la librería time.h o gettimeofday() de sys/time.h (investigar).
*/

#include "basiclib.h"
#include <sys/time.h>
#define MAX_VALUE 20
#define BURBUJA 1
#define INSERCION 2
#define SELECCION 3
#define SHELLSORT 4

void swap(int *x, int *y) {
	int aux = *x;
	*x = *y;
	*y = aux;
}

int* InitVec(int dim) {
	int *p = NULL;
	p = (int*)malloc(dim*sizeof *p);
	for (int i = 0; i < dim; ++i)
		p[i] = rand()%MAX_VALUE;
	return p;
}

void PrintV(int *vec, int dim) {
	for (int i = 0; i < dim; ++i)
		printf("%d ", vec[i]);
	puts("");
}

void BubbleSort(int *vector, int dim) {
	int i, j, aux;
	for(i = 0; i < dim; i++) {
		for(j = i+1; j < dim; j++) {
			if (vector[j] < vector[i])
				swap(&vector[i], &vector[j]);
		}
	}
}

void InsertionSort(int *vector, int dim) {
	int i, j, aux;
	for(i = 0; i < dim; i++) {
		aux = vector[i];
		j = i - 1;
		while ((j >= 0) && (vector[j] > aux)) {
			vector[j+1] = vector[j];
			j--;
		}
		vector[j+1] = aux;
	}
}

void SelectionSort(int *vector, int dim) {
	int i, j, k, p, aux, limite = dim-1;
	for(k = 0; k < limite; k++) {
		p = k;
		for (i = k + 1; i <= limite; i++) {
			if (vector[i] < vector[p])
				p = i;
		}
		if (p != k)
			swap (&vector[p], &vector[k]);
		}
}

void ShellSort(int *vector, int dim) {
	int i, j,aux, incr = dim;
	do {
		for (i = incr; i < dim; i++) {
			for (j = i; (j >= incr) && (vector[j-incr]>vector[j]); j -= incr)
				swap(&vector[j], &vector[j-incr]);
		}
		incr >>= 1;
	} while (incr >0);
}

int main() {
	struct timeval begin, end;
	gettimeofday(&begin, NULL);
	clock_t t2 = clock();
	int *v, dim, op = 0;
	void(*method)(int*, int);
	puts("Ingrese tamaño del vector:");
	scanf("%d", &dim);
	v = InitVec(dim);
	PrintV(v, dim);
	printf("Que metodo de ordenamiento desea realizar?\n1)- Burbuja\n2)- Insercion\n3)- Seleccion\n4)- ShellSort\n");
	scanf("%d", &op);
	switch(op) {
		case BURBUJA:
			method = BubbleSort;
			break;
		case INSERCION:
			method = InsertionSort;
			break;
		case SELECCION:
			method = SelectionSort;
			break;
		case SHELLSORT:
			method = ShellSort;
			break;
		default:
			puts("Error: Input invalido.");
			exit(-1);
	}
	method(v, dim);
	PrintV(v, dim);
	free(v);
	gettimeofday(&end, NULL);
	double t1 = (end.tv_sec - begin.tv_sec) + ((end.tv_usec - begin.tv_usec)/1000000.0f);
	t2 = clock() - t2;
	printf("Tiempo de ejecucion (gettimeofday) : %f segundos\nTiempo de ejecucion (clock): %f segundos (%d ticks)\n", t1, ((float)t2)/CLOCKS_PER_SEC, t2);
	return 0;
}