#include "ABB.h"

void Quits() {
	puts("Error: Memoria insuficiente para alocar nodo.");
	exit(-1);
}

/*Destruye el arbol y limpia la memoria*/
void DestruirArbol(Arbol_T a) {
	if( a != NULL ) {
		DestruirArbol(a->izq);
		DestruirArbol(a->der);
		free(a);
	}
}

/* Crea un arbol con un nodo con x como dato. Hijo izq e hijo der son árboles vacíos (NULL) */
Arbol_T CrearArbol(Tipo_Dato x) {
	Arbol_T a;
	if ( (a = (Arbol_T)malloc(sizeof(struct Nodo))) == NULL )
		Quits();
	a->izq = NULL;
	a->der = NULL;
	a->dato = x;
	return a;
}

/* Inserta el elemento "dato" en el ABB */
void InsertarElemento(Arbol_T *a, Tipo_Dato dato) {
	if ( *a == NULL )
		*a = CrearArbol(dato);
	else {
		if ( dato < (*a)->dato )
			InsertarElemento(&(*a)->izq, dato);
		else
			InsertarElemento(&(*a)->der, dato);
	}
}

/* Procesa el ABB a en orden */
void InOrder(Arbol_T a) {
	if (a != NULL) {
		InOrder(a->izq);
		printf("%d ", a->dato);
		InOrder(a->der);
	}
}

/* Procesa el ABB a con orden pre-orden */
void PreOrder(Arbol_T a) {
	if (a != NULL) {
		printf("%d ", a->dato);
		PreOrder(a->izq);
		PreOrder(a->der);
	}
}

/* Procesa el ABB a en orden post-orden */
void PostOrder(Arbol_T a) {
	if (a != NULL) {
		PostOrder(a->izq);
		PostOrder(a->der);
		printf("%d ", a->dato);
	}

}

/*Devuelve el valor minimo de un arbol*/
Arbol_T ValorMin(Arbol_T a) {
	Arbol_T temp = a;
	while (temp->izq != NULL)
		temp = temp->izq;
	return temp;
}

/* elimina el elemento dato del ABB a */
Arbol_T EliminarElemento(Arbol_T a, Tipo_Dato dato) {
	if (a == NULL) {
		return NULL;
	}
	if (dato < a->dato) { // dato esta en el lado izquierdo
			a->izq = EliminarElemento(a->izq, dato);
	}
	else if (dato > a->dato) { // dato esta en el lado derecho
			a->der = EliminarElemento(a->der, dato);
	}
	else {
		// caso 1: el arbol no tiene hijos
		if (a->izq == NULL && a->der == NULL) {
				free(a);
				a = NULL;
		}
		// caso 2: dos hijos
		else if ( a->izq != NULL && a->der != NULL) {
				Arbol_T temp = ValorMin(a->der); // Encontral el valor minimo en el lado derecho del arbol
				a->dato = temp->dato; // duplicar el nodo
				a->der = EliminarElemento(a->der, temp->dato); // borrar el nodo duplicado
		}
		// caso 3: 1 hijo (der)
		else if ( a->der != NULL && a->izq == NULL) {
				Arbol_T temp = a; // copia temporal del nodo
				a = a->der;
				free(temp);
		}
		// caso 4: 1 hijo (izq)
		else if (a->izq != NULL && a->der == NULL) {
				Arbol_T temp = a; // copia temporal del nodo
				a = a->izq;
				free(temp);
		}
	}
	return a;
}


/* Retorna true si el elemento dato existe en el ABB a */
int Existe(Arbol_T a, Tipo_Dato dato) {
	if (a == NULL)
		return 0;
	else {
		if (a->dato == dato)
			return 1;
		else { // busco en el hijo que corresponda
			if ( dato < a->dato )
				Existe(a->izq, dato);
			else
				Existe(a->der, dato);
		}
	}
}

/* Retorna la cantidad de nodos del ABB a */
int ContarNodos(Arbol_T a) {
	if ( a == NULL )
			return 0;
	else
			return 1 + ContarNodos(a->izq) + ContarNodos(a->der);
}

/* Retorna el valor máximo del ABB a (nota: datos menores hacia la izquierda)*/
int Maximo(Arbol_T a) {
	if( a == NULL)
		return 0;
	else {
		Arbol_T cur = a;
		while ( cur->der != NULL)
			cur = cur->der;
		return cur->dato;
	}
}

/*Retorna en valor mínimo del ABB a */
int Minimo(Arbol_T a) {
	if( a == NULL)
		return 0;
	else {
		Arbol_T cur = a;
		while ( cur->izq != NULL)
			cur = cur->izq;
		return cur->dato;
	}
}

/* funcion auxiliar que retorna el maximo entre dos elementos int */
int obtenerMax(int a, int b) {
	return (a < b) ? b : a;
}

/* retorna la profundidad del ABB a */
int Profundidad(Arbol_T a) {
	if ( a == NULL) 
		return 0;
	int profundidad_izq = Profundidad(a->izq);
	int profundidad_der = Profundidad(a->der);
	return 1 + obtenerMax(profundidad_izq, profundidad_der);
};

void Menu(Arbol_T a) {
	int op = 0, busqueda;
	Tipo_Dato elemento;
	do {
		puts("Que desea realizar?");
		printf("1)-Agregar dato\n2)-Eliminar dato\n3)-Imprimir lista\n4)-Imprimir informacion del arbol\n5)-Buscar elemento\n0)-Salir\n");
		if(!scanf("%d", &op)) {
			puts("Error de input.");
			exit(-1);
		}
		switch(op) {
			case 0: break;
			case AGREGAR:
				printf("Ingrese el elemento que desea ingresar: ");
				if(!scanf("%d", &elemento)) {
					puts("Error de input.");
					exit(-1);
				}
				InsertarElemento(&a, elemento);
				printf("Elemento %d agregado.\n", elemento);
				break;
			case ELIMINAR:
				printf("Ingrese el elemento que desea eliminar: ");
				if(!scanf("%d", &elemento)) {
					puts("Error de input.");
					exit(-1);
				}
				a = EliminarElemento(a, elemento);
				printf("Elemento %d eliminado.\n", elemento);
				break;
			case IMPRIMIR:
				if ( a == NULL ) //El arbol esta vacio
					puts("No se puede imprimir (el arbol esta vacio).");
				else {
					puts("Ingrese modo de impresion.");
					printf("1)-En Orden\n2)-Pre Orden\n3)-Post Orden\n");
					if(!scanf("%d", &busqueda)) {
						puts("Error de input.");
						exit(-1);
					}
					switch(busqueda) {
						case 1:
							InOrder(a);
							puts("");
							break;
						case 2:
							PreOrder(a);
							puts("");
							break;
						case 3:
							PostOrder(a);
							puts("");
							break;
					}
				}
				break;
			case INFO:
				printf("El arbol tiene %d niveles y %d nodos.\n", Profundidad(a), ContarNodos(a));
				printf("Valor Maximo: [%d]\nValor Minimo: [%d]\n", Maximo(a) , Minimo(a));
				break;
			case BUSQUEDA:
				printf("Ingrese el elemento que desea buscar: ");
				if(!scanf("%d", &elemento)) {
					puts("Error de input.");
					exit(-1);
				}
				if ( Existe(a, elemento) ) {
					printf("El elemento %d existe en el arbol.\n", elemento);
				}
				else
					printf("El elemento %d no existe en el arbol.\n", elemento);
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}
