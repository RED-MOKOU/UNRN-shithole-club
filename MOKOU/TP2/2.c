/* UNRN PyA - Jose Emanuel Suez

2) A continuacion se describe el ejemplo del libro “Introduccion a la Programacion en C” de los autores
Marco A. Peña Basurto y Jose M. Cela Espin (Aula Politecnica /ETSETB). Dicho ejemplo está en el capítulo
9, ejemplificando el uso de punteros y tablas. Analizar y describir que es lo que hace este codigo.*/

/*Este ejemplo crea dos arrays de dimension DIM, le pide al usuario que ingrese sus valores, y luego compara la
sumatoria de dichos valores. Le asigna la direccion del vector mas "fuerte" al pointer *fuerte, y luego lo recorre e imprime.*/

#include <stdio.h>
#define DIM 10

int main()
{
	int v1[DIM], v2[DIM];
	int fuerza1, fuerza2, i;
	int *fuerte;

	/* lectura de los vectores */
	for(i=0; i <DIM; i++) {
		scanf(“%d ”, &v1[i]);
	}
	for(i=0; i <DIM; i++) {
		scanf(“%d ”, &v2[i]);
	}

	/* cálculo de fuerza de los vectores */
	fuerza1 = fuerza2 = 0;

	for(i=0; i <DIM; i++) {
		fuerza1 += v1[i];
		fuerza2 += v2[i];
	}
	if (fuerza1 >fuerza2)
		fuerte = v1;
	else
		fuerte = v2;
	
	/* escritura del vector más fuerte */
	for(i=0; i <DIM; i++) {
		printf(“%d ”, fuerte[i]);
	}
	return 0;
}