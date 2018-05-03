/*10) El TAD Lista Ordenada, es similar a la lista simple, pero cada elemento que se ingresa tiene un campo
clave. La función insertar analiza ese campo clave para ingresar el elemento en la posición correcta. La función
insertar ya no recibe la posición del elemento. Para comparar los elementos existe la función ComparaElemento(
Tipo_elemento A, Tipo_Elemento B) que devuelve -1 si A<B, 0 si A=B y 1 si A>B. Implementar este
TpAD para elementos del tipo complejo donde se pide que queden ordenados por su magnitud (magnitud de z =
sqrt(re(z)^2+im(z)^2).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "TADlist.h"
#define AGREGAR 1
#define IMPRIMIR 2

typedef struct Nodo {
	int x, y;
	float z;
	struct Nodo *next;
} tsNode;

typedef struct {
	int n;
	tsNode *head;
} tsLista;

/*Compara los elementos a y b. Devuelve 0 si (a == b), -1 si (a < b), y 1 si (a > b)*/
int ComparaElemento(float a, float b) {
	if(a == b)
		return 0;
	else
		return (a < b) ? -1 : 1;
}

/*Devuelve la magintud del numero complejo*/
float Magnitud(int x, int y) {
	return sqrt(x*x + y*y);
}

/*Inserta el elemento en el nodo correspondiente al comparar su z con el de los otros elementos en la lista.
Como la lista se va llenando de forma ordenada de menor a mayor (ordena al momento de insertar el nodo), solo
hay que encontrar el elemento con z mayor que el que se quiere insertar, y colocar nuestro elemento detras
de aquél. La funcion retorna la posicion que se le asignó al nuevo elemento dentro de la lista (contando desde 1).*/
int InsertarOrdenado(tsLista *l, tsNode node) {
	tsNode *new_node = NULL;
	if((new_node = (tsNode*)malloc(sizeof(tsNode))) == NULL) {
		puts("Error: Memoria insuficiente para crear nuevo nodo.");
		exit(-1);
	}
	*new_node = node;
	if(l->n == 0) { //no hay elementos
		new_node->next = NULL;
		l->head = new_node;
		++(l->n);
		return 1;
	}
	tsNode *curr = l->head, *previous;
	for (int i = 1; i <= l->n; ++i) {
		if( (ComparaElemento(curr->z, new_node->z) > -1) ) {
			if(i == 1) { //nuevo primer elemento
				new_node->next = l->head;
				l->head = new_node;
				++(l->n);
				return i;
			}
			else {
				previous->next = new_node;
				new_node->next = curr;
				++(l->n);
				return i;
			}
		}
		else {
			if(i == l->n) { //ultimo elemento
				curr->next = new_node;
				new_node->next = NULL;
				++(l->n);
				return i;
			}
			else { //var update
				previous = curr;
				curr = curr->next;
			}
		}
	}
}


/*Recorre la lista “l” imprimiendo sus elementos. Retorna 1 si la operación se realiza con éxito, 0 caso contrario (la lista no tiene elementos).*/
int RecorrerLista(tsLista l) {
	if(l.n < 0)
		return 0;
	else {
		tsNode *curr = l.head;
		puts("*-------------*");
		while(curr != NULL) {
			printf("[%d,%di] (z = %1.2f)\n", curr->x, curr->y, curr->z);
			curr = curr->next;
		}
		puts("*-------------*");
		return 1;
	}
}

/*Desaloca la memoria de cada nodo. Longitud de la lista = 0. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.*/
int VaciarLista(tsLista *l) {
	printf("Saliendo: Preparandose para vaciar la lista.\n");
	if(l->n > 0) {
		tsNode *head = l->head, *curr;
		while ((curr = head) != NULL) {
			head = head->next;
			free(curr);
			printf(".");
		}
		puts("");
		l->n = 0;
		return 1;
	}
	else
		return 0;
}

/*Menu de uso*/
void PrintMenu(tsLista *list) {
	tsNode temp;
	int op = 0, result;
	do {
		puts("Que desea realizar?");
		puts("1)-Agregar dato\n2)-Imprimir lista\n0)-Salir\n");
		if(!scanf("%d", &op)) {
			puts("Error de input.");
			exit(-1);
		}
		switch(op) {
			case 0: break;
			case AGREGAR:
				puts("Ingrese los campos del numero complejo que desea agregar:");
				if(!scanf("%d %d", &(temp.x), &(temp.y))) {
					puts("Error de input.");
					exit(-1);
				}
				temp.z = Magnitud(temp.x, temp.y);
				result = InsertarOrdenado(list, temp);
				if(result){
					printf("El dato [%d,%di] (z = %1.2f) fue agregado en la posicion %d\n", temp.x, temp.y, temp.z, result);
				}
				break;
			case IMPRIMIR:
				if(RecorrerLista(*list) != 1)
					puts("La lista esta vacia.");
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}

int main() {
	tsLista list;
	list.n = 0;
	PrintMenu(&list);
	if(VaciarLista(&list))
		printf("La lista ha sido vaciada.\n");
	else
		printf("La lista no tenia elementos para vaciar.\n");
	return 0;
}
