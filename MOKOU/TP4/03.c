/*3) Usando una pila de caracteres, indicar si una palabra es un palíndromo (que se lee igual en ambos sentidos).
Ayuda: leer la palabra caracter a caracter, armando a la vez un string y una pila. Luego, utilizar la pila y el string
para comparar los caracteres. Puede utilizar la función getchar() para leer los caracteres hasta el fin de línea.*/

#include <stdio.h>
#include <stdlib.h>

typedef char Tipo_Dato;

typedef struct {
	Tipo_Dato *pila;
} tsPila;

/*Añade x a la pila, si la misma no está llena.*/
void Q_Push(tsPila *pila, Tipo_Dato x ) {
	if(pila->indice <= pila->max) {
		pila->pila[(pila->indice)++] = x;
	}
}

/*Saca un elemento de la pila si la pila no está vacía. La función retorna dicho dato.*/
Tipo_Dato Q_Pop(tsPila *pila) {
	if(pila->indice > 0) {
		return pila->pila[(pila->indice)--];
	}
	else {
		puts("Error: La pila esta vacia.");
	}
}

/*Lee el stdin, copia letra a letra la palabra en str, y agrega cada letra a la pila. Retorna str*/
char *ReadString(tsPila *p) {
	char *str;
	int ch, len = 0;
	if( (str = (char*)malloc(((p->max)+1)*sizeof *str)) == NULL ) {
		puts("Error: Memoria insuficiente.");
		exit(-1);
	}
	puts("Ingrese la palabra que desea analizar:");
	while( (ch = fgetc(stdin)) != ' ' && ch != '\n' ) {
		if( len == p->max ) {
			puts("Error: Buffer overflow (la palabra es demasiado larga)");
			exit(-1);
		}
		Q_Push(p, (char)ch);	// FIXME: el indice termina siendo 1 numero mas grande de lo debido.
		str[len++] = ch;
	}
	--(p->indice);	// Fixed
	str[len] = '\0';
	return str;
}

/*Compara las letras metódicamente para analizar si la palabra es un palindromo*/
int Comparacion(tsPila *q, char *s) {
	int comparaciones = 0;	// Comparaciones positivas
	int letras = q->indice;	// Dado que en Q_Pop se modifica el indice, se lo copia para hacer la comparacion al final.
	for (int i = 0; i < letras; ++i) {
		if( Q_Pop(q) ==  s[i] )
			++comparaciones;
	}
	return (comparaciones == letras) ? 1 : 0;
}

int main() {
	char *string = NULL;
	tsPila q = { .indice = 0, .max = 30}; //30 es un valor arbitrario tomando el cuenta el largo de la palabra mas larga del idioma (24 caracteres)
	if ( (q.pila = (Tipo_Dato*)malloc(q.max*sizeof(Tipo_Dato))) == NULL) {
		puts("Error: Memoria insuficiente.")
		exit(-1);
	}
	string = ReadString(&q);
	printf("La palabra \"%s\" ", string);
	if( Comparacion(&q, string) )
		puts("es un palindromo.");
	else
		puts("no es un palindromo.");
	return 0;
}
