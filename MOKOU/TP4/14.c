/*14) Encontrar un número capicúa leído del dispositivo estándar de entrada (usando pilas o colas o ambas). NO
acceder a la estructura, usar funciones del TAD.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char Tipo_Dato
#include "pila_pointer.h"
#define MAX 20

void Quits() {
	puts("Error: Memoria insuficiente.");
	exit(-1);
}

/*Lee el stdin, copia letra a letra la palabra en str. Retorna str*/
char *ReadString() {
	char *str;
	int ch, len = 0, size = MAX;
	if ( (str = (char*)malloc(size*sizeof *str)) == NULL )
		Quits();
	puts("Ingrese un numero:");
	while( (ch = fgetc(stdin)) != ' ' && ch != '\n' ) {
		str[len++] = ch;
		if ( len == size ) {
			if ( (str = realloc(str, (size+=10)*sizeof *str)) == NULL )
				Quits();
		}
	}
	str[len]='\0';
	return realloc(str, sizeof(char)*len);
}

void CopiarStr(Pila_T *p, char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; ++i)
		S_Push(p, s[i]);
}

int Comparacion(Pila_T *p, char *s) {
	int len = strlen(s), comparaciones = 0;
	for (int i = 0; i < len; ++i) {
		if ( S_Pop(p) == s[i] )
			++comparaciones;
	}
	return ( comparaciones == len ) ? 1 : 0;
}

int main() {
	char *str = ReadString();
	Pila_T pila = Crear_Pila(strlen(str));
	CopiarStr(&pila, str);
	printf("El numero \"%s\" ", str);
	if( Comparacion(&pila, str) )
		printf("es capicua.\n");
	else
		printf("no es capicua.\n");
	free(str);
	if( Vaciar_Pila(&pila) )
		puts("La memoria ha sido vaciada.");
	return 0;
}
