/*4) Escribir y ejecutar un programa que lea la informacion de una pelicula: nombre, director, año, codigo.
Realizar funciones para leer la informacion de una pelicula y para mostrar por pantalla la informacion de una
pelicula.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nombre[30];
	char director[30];
	int anio;
	int codigo;
} tsPelicula;

void PrintM(tsPelicula *p) {
	printf("---\nNombre: %s\nDirector: %s\nAño: %d\nCodigo: %d\n---\n", p->nombre, p->director, p->anio, p->codigo);
}

tsPelicula Leer() {
	tsPelicula pelicula;
	int i = 0;
	puts("Ingrese nombre de la pelicula:");
	scanf ("%[^\n]%*c", pelicula.nombre);
	puts("Ingrese nombre del director de la pelicula:");
	scanf ("%[^\n]%*c", pelicula.director);
	puts("Ingrese el año de la pelicula:");
	scanf("%d", &pelicula.anio);
	puts("Ingrese el codigo de la pelicula:");
	scanf("%d", &pelicula.codigo);
	return pelicula;
}

int main() {
	tsPelicula pel = Leer();
	PrintM(&pel);
	return 0;
}
