/*7) El tipo de dato pila se puede utilizar para determinar si una expresión está “balanceada”. Por ejemplo,
tomando una expresión algebraica como: 7+[5*(3+8)]/(7+9) se puede determinar que la expresión está
balanceada: cada símbolo de apertura “{”, “[” o “(” tiene su símbolo de cierre “}”, “]” o “)”. Escribir un
programa que dada una secuencia de caracteres, determine si la secuencia está balanceada o no. Puede utiizar
la función getchar() para leer los caracteres hasta el fin de linea.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Tipo_Dato;
typedef struct {
	int indice; // tope de la pila
	Tipo_Dato *pila; // pila
	int max;
} Pila_T;

/*Variable global para facilitar el acceso*/
int string_len = 0;

//Crea la pila pasada como parámetro: con 0 elementos y asignando el valor correcto al resto de los
//campos. O esta función puede no recibir parámetros y devolver un dato de tipo Pila_T
Pila_T Crear_Pila(int max) {
	Pila_T out = (Pila_T){ .indice = 0, .max = max};
	if( (out.pila = (Tipo_Dato*)malloc(max*sizeof(Tipo_Dato))) == NULL) {
		puts("Error: No hay memoria disponible.");
		exit(-1);
	}
	return out;
}

//Añade x a la pila, si la misma no está llena.
//Retorna 1 si se agrega x con exito, 0 en caso contrario.
int Q_Push(Pila_T *pila, Tipo_Dato x ) {
	if(pila->max > pila->indice) {
		++(pila->indice);
		pila->pila[pila->indice] = x;
		return 1;
	}
	else {
		puts("Error: No se puede agregar el dato (la pila esta llena).");
		return 0;
	}
}

//Saca un elemento de la pila si la pila no está vacía. La función retorna dicho dato.
Tipo_Dato Q_Pop(Pila_T *pila) {
	if(pila->indice > 0) {
		--(pila->indice);
		return pila->pila[(pila->indice)+1];
	}
	else {
		puts("Error: La pila esta vacia.");
	}
}

//Vacia la pila pasada como parámetro.
int Vaciar_Pila(Pila_T *pila){
	free(pila->pila);
}

/*Lee el stdin, copia letra a letra la palabra en str. Retorna str*/
char *ReadString() {
	char *str;
	int ch, size = 10, len = 0;
	if( (str = (char*)malloc(size*sizeof *str)) == NULL ) {
		puts("Error: Memoria insuficiente.");
		exit(-1);
	}
	puts("Ingrese la cadena a analizar:");
	while( (ch = fgetc(stdin)) != '\n' ) {
		str[len++] = ch;
		if(len == size){
			if( (str = realloc(str, sizeof(*str)*(size+=10))) == NULL ) {
				puts("Error: Memoria insuficiente.");
				exit(-1);
			}
		}
	}
	str[len] = '\0';
	return str;
}

/*Analiza la cadena "string". Si encuentra algun simbolo de apertura, lo agrega a la pila correspondiete.
Si encuentra un simbolo de cierre, lo saca de la pila correspondiente.
La variable "balanceado" se vuelve 0 en caso de que haya un simbolo de cierre que no tenga su par de abertura.
Si todas las pilas estan vacias y balanceado es igual a 1, la expresion esta balanceada.
Retorna 1 en si esta balanceada, 0 en caso contrario.*/
int Balance(char *string, Pila_T *Parentesis, Pila_T *Corchetes, Pila_T *Llaves) {
	int balanceado = 1;
	for (int i = 0; i < string_len && balanceado; ++i) {
		printf("[FOR] Balanceado: %d\n", balanceado);
		switch (string[i]) {
			case '(':
				Q_Push(Parentesis, string[i]);
				break;
			case '[':
				Q_Push(Corchetes, string[i]);
				break;
			case '{':
				Q_Push(Llaves, string[i]);
				break;
			case ')':
			case ']':
			case '}':
				if( (Parentesis->indice == 0) && (Corchetes->indice == 0) && (Llaves->indice == 0) )
					balanceado = 0;
				else  {
					if ( string[i] == ')') Q_Pop(Parentesis);
					if ( string[i] == ']') Q_Pop(Corchetes);
					if ( string[i] == '}') Q_Pop(Llaves);
				}
				break;
		}
	}
	printf("[OUTFOR] Balanceado: %d\n", balanceado);
	printf("Parentesis:%d\nCorchetes:%d\nLlaves:%d\n", Parentesis->indice, Corchetes->indice, Llaves->indice);
	if ( balanceado && ( (Parentesis->indice == 0) && (Corchetes->indice == 0) && (Llaves->indice == 0) ) )
		return 1;
	else
		return 0;
}

int main() {
	char *str = ReadString();
	string_len = strlen(str); // Se toma el largo del input como maximo para las pilas
	Pila_T Parentesis = Crear_Pila(string_len), Corchetes = Crear_Pila(string_len), Llaves = Crear_Pila(string_len);

	/*Impresion por pantalla*/
	printf("La expresion \"%s\"", str);
	if ( Balance(str, &Parentesis, &Corchetes, &Llaves) )
		printf(" esta balanceada.\n");
	else
		printf(" no esta balanceada.\n");

	/*Liberacion de memoria*/
	Vaciar_Pila(&Parentesis);
	Vaciar_Pila(&Corchetes);
	Vaciar_Pila(&Llaves);
	free(str);
	return 0;
}
