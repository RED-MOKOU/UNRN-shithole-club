/*19) Un arreglo contiene los elementos indicados más abajo. Utilizando el agoritmo de ordenación Shell encuentre
las pasadas y los intercambios que se realizan para su ordenación.
{8, 43, 17, 6, 40, 16, 18, 97, 11, 7}*/

/*Intercambios: 12
Pasadas: 4*/

#include <stdio.h>
#define SIZE 10
int intercambios = 0;
int pasadas = 0;

void printv(int v[SIZE]) {
	int i;
	for( i = 0; i < SIZE; i++)
		printf("%d ", v[i]);
	puts("");
}

void swapint(int *x, int *y) {
	int aux = *x;
	*x = *y;
	*y = aux;
}

void ShellSort(int vector[SIZE]) {
	int i, j, aux, incr = SIZE;
	do {
		for (i = incr; i < SIZE; i++) {
			for (j = i; (j>=incr) && (vector[j-incr]>vector[j]); j -= incr) {
				swapint(&vector[j], &vector[j-incr]);
				intercambios++;
				}
		}
		incr = incr / 2;
		pasadas++;
	} while (incr > 0);
}

int main() {
	int arr[] = {8, 43, 17, 6, 40, 16, 18, 97, 11, 7};
	printv(arr);
	ShellSort(arr);
	printv(arr);
	printf("Intercambios: %d\nPasadas: %d", intercambios, pasadas);
	return 0;
}