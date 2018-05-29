/*11) Reescribir el ejercicio 3) para descubrir si una frase es palíndroma. Esta vez, utilizar pilas y colas de caracteres.
NO acceder a la estructura, usar funciones del/los TAD/s.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char Tipo_Dato;
#include "pila_pointer.h"
#include "cola_pointer.h"
#define MAX 30

void Quits() {
	puts("Error: Memoria insuficiente.");
	exit(-1);
}

/*Lee el stdin, copia letra a letra la palabra en str, y agrega cada letra a la pila. Retorna str*/
char *ReadString(Pila_T *pila, Cola_T *cola) {
	char *str;
	int ch, len = 0;
	if( (str = (char*)malloc((MAX+1*sizeof *str))) == NULL )
		Quits();
	puts("Ingrese la palabra que desea analizar:");
	while( (ch = fgetc(stdin)) != ' ' && ch != '\n' ) {
		if( len == MAX ) {
			puts("Error: Buffer overflow (la palabra es demasiado larga)");
			exit(-1);
		}
		S_Push(pila, (Tipo_Dato)ch);
		Q_Push(cola, (Tipo_Dato)ch);
		str[len++] = ch;
	}
	str[len] = '\0';
	return str;
}

/*Compara las letras metódicamente para analizar si la palabra es un palindromo*/
int Comparacion(Pila_T *pila, Cola_T *cola, char *s) {
	int comparaciones = 0, longitud;
	if ( (longitud = strlen(s)) % 2 == 0 ) // Si la cantidad de letras es par
		longitud >>= 1;
	else
		longitud = 1+longitud>>1;
	for (int i = 0; i < longitud; ++i) {
		if( S_Pop(pila) ==  Q_Pop(cola) )
			++comparaciones;
	}
		return ( comparaciones == longitud ) ? 1 : 0;
}

int main() {
	char *string = NULL;
	Pila_T pila = Crear_Pila(MAX);
	Cola_T cola; Crear_Cola(&cola);
	string = ReadString(&pila, &cola);
	printf("La palabra \"%s\" ", string);
	if( Comparacion(&pila, &cola, string) )
		puts("es un palindromo.");
	else
		puts("no es un palindromo.");
	return 0;
}
