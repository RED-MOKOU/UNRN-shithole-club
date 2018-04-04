/*#22) Se realiza una encuesta anonima sobre 50 personas, donde de cada una se conoce la edad y la cantidad
de hijos. Luego de ingresar los datos, se procesan los datos para obtener: 1. El listado de los 50 participantes,
ordenados por edad e informando edad y cantidad de hijos. Utilizar el método de insercion para realizar la
ordenacion. 2. Un listado donde se informe el promedio de hijos para cada una de las edades consideradas
(establecer como pre-condicion el rango de edades que se usara). */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 50

typedef struct {
	int edad, hijos;
} tsPersona[SIZE];

void PrintAr(tsPersona n) {
	int i;
	for(i = 0; i < SIZE; i++) {
		if( (i%5 == 0) && (i != 0))
			puts("");
		printf("[Edad: %2d; Hijos: %d] ", n[i].edad, n[i].hijos);
	}
	puts("");
}

void InitAr(tsPersona a) {
	int i;
	for( i = 0; i < SIZE; i++) {
		a[i].edad = rand()%60+20; //edad entre 20 y 80
		a[i].hijos = rand()%5; //entre 0 y 5 hijos
	}
}

void InsertionSort(tsPersona v) {
	int i, j, aux;
	for(i=0; i < SIZE; i++) {
		aux = v[i].edad;
		j = i - 1;
		while ((j>=0) && (v[j].edad > aux)) {
			v[j+1].edad = v[j].edad;
			j--;
		}
		v[j+1].edad = aux;
	}
}

void Prom(tsPersona p) {
	int i;
	int s1 = 0, p1 = 0; //Entre 20 y 30
	int s2 = 0, p2 = 0; //Entre 30 y 40
	int s3 = 0, p3 = 0; //Entre 40 y 50
	int s4 = 0, p4 = 0; //Entre 50 y 60
	int s5 = 0, p5 = 0; //Entre 60 y 70
	int s6 = 0, p6 = 0; //Entre 70 y 80
	for(i = 0; i < SIZE; i++) {
		if(p[i].edad <= 30) {
			s1 += p[i].hijos;
			p1++;
		}
		if(p[i].edad >= 30 && p[i].edad <= 40) {
			s2 += p[i].hijos;
			p2++;
		}
		if(p[i].edad >= 40 && p[i].edad <= 50) {
			s3 += p[i].hijos;
			p3++;
		}
		if(p[i].edad >= 50 && p[i].edad <= 60) {
			s4 += p[i].hijos;
			p4++;
		}
		if(p[i].edad >= 60 && p[i].edad <= 70) {
			s5 += p[i].hijos;
			p5++;
		}
		if(p[i].edad >= 70 && p[i].edad <= 80) {
			s6 += p[i].hijos;
			p6++;
		}
	}
	printf("El promedio de hijos entre personas de 20 y 30 es: %0.2f\n", (float)s1/p1);
	printf("El promedio de hijos entre personas de 30 y 40 es: %0.2f\n", (float)s2/p2);
	printf("El promedio de hijos entre personas de 40 y 50 es: %0.2f\n", (float)s3/p3);
	printf("El promedio de hijos entre personas de 50 y 60 es: %0.2f\n", (float)s4/p4);
	printf("El promedio de hijos entre personas de 60 y 70 es: %0.2f\n", (float)s5/p5);
	printf("El promedio de hijos entre personas de 70 y 80 es: %0.2f\n", (float)s6/p6);
}

int main() {
	tsPersona arr;
	InitAr(arr);
	InsertionSort(arr);
	PrintAr(arr);
	Prom(arr);
	return 0;
}