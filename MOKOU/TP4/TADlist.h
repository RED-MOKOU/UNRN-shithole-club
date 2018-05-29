/*PyA UNRN - Jose Emanuel Suez

*/

#ifndef __TADLIST__
#define __TADLIST__
#define AGREGAR 1
#define ELIMINAR 2
#define IMPRIMIR 3
#define BUSCAR 4

typedef struct Nodo {
	Tipo_Dato dato;
	struct Nodo *sig;
} tsNodo;

typedef struct {
	int n;
	tsNodo *lista;
} Lista_T;

Lista_T CrearLista();
int InsertarPrimero(Lista_T*, Tipo_Dato);
int InsertarUltimo(Lista_T*, Tipo_Dato);
int RecorrerLista(Lista_T);
int EstaVacia(Lista_T);
int VaciarLista(Lista_T*);
int SuprimirDato(Lista_T*, Tipo_Dato);
int SuprimirNodo(Lista_T*, int);
int LongitudLista(Lista_T);
int DevolverDatoPosicion(Lista_T, int);
void Menu(Lista_T*);
void SuprimirPrimerElemento(Lista_T*);
void SuprimirUltimoElemento(Lista_T*);
void InsertarOrdenado(Lista_T*);
void Quits();

/*Crea una lista del tipo Lista_T con 0 elementos y la retorna (lista vacía).*/
Lista_T CrearLista() {
	Lista_T l;
	l = (Lista_T){.n = 0, .lista = NULL};
	return l;
}

/*Inserta nodo con elemento x como primer elemento de la lista. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.*/
int InsertarPrimero(Lista_T *l, int x) {
	tsNodo *nuevo = NULL;
	if((nuevo = (tsNodo*)malloc(sizeof(tsNodo))) == NULL) {
		Quits();
	}
	nuevo->dato = x;
	nuevo->sig = NULL;
	l->lista = nuevo;
	++(l->n);
	return 1;
}

/*Inserta nodo con elemento x como último elemento de la lista. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.*/
int InsertarUltimo(Lista_T *l, int x ) {
	tsNodo *temp, *nuevo;
	if ((nuevo = (tsNodo*)malloc(sizeof(tsNodo))) == NULL) {
		printf("No hay memoria disponible.\n");
		return 0;
	} 
	nuevo->dato = x;
	nuevo->sig = NULL; //ultimo elemento en la lista
	if (!EstaVacia(*l)) {
		temp = l->lista;
		while (temp->sig != NULL)
			temp = temp->sig;
		temp->sig = nuevo; //temp esta en el ultimo nodo, se actualiza su campo siguiente para que apunte a "nuevo"
	}
	++(l->n);
	return 1;
}

/*Recorre la lista “l” imprimiendo sus elementos. Retorna 1 si la operación se realiza con éxito, 0 caso contrario (la lista no tiene elementos).*/
int RecorrerLista(Lista_T l) {
	tsNodo *elemento;
	if(l.n < 0)
		return 0;
	else  {
		elemento = l.lista; // n apunta al primer elemento de la lista
		puts("");
		while (elemento != NULL) {
			printf("%d ",elemento->dato);
			elemento = elemento->sig;
		}
	}
	printf("\n\n");
	return 1;
}

/*Retorna TRUE (1) si la lista está vacía, FALSE (0) caso contrario.*/
int EstaVacia(Lista_T l) {
	return (l.n) ? 0 : 1;
}

/*Desaloca la memoria de cada nodo. Longitud de la lista = 0. Retorna 1 si la operación se realiza con éxito, 0 caso contrario.*/
int VaciarLista(Lista_T *l) {
	tsNodo *head, *curr;
	printf("Vaciando lista");
	if(l->n > 0) {
		head = l->lista;
		while ((curr = head) != NULL) {
			head = head->sig;
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

/*Elimina el nodo con el dato x de la lista. Retorna 1 si el dato esta en la lista (y es eliminado), 0 en caso contrario.*/
int SuprimirDato(Lista_T *l, int x) {
	tsNodo *curr, *temp = NULL;
	int pos = 0;
	if(l->n) {
		if ((l->lista)->dato == x) { //Primer elemento
			SuprimirPrimerElemento(l);
			--(l->n);
			return 1;
		}
		curr = l->lista;
		while ((curr->sig)->dato != x) {
			curr = curr->sig;
			++pos;
		}
		if(pos == (l->n)-1) { //ultimo elemento
			SuprimirUltimoElemento(l);
			--(l->n);
			return 1;
		}
		else if ((curr->sig)->dato == x) {
			temp = curr->sig;
			curr->sig = temp->sig;
			free(temp);
			--(l->n);
			return 1;
		}
		else
			return 0;
	}
}

/*Elimina el nodo con posición pos de la lista. Retorna 1 si el dato esta en la lista (y es eliminado), 0 en caso contrario.*/
int SuprimirNodo(Lista_T *l, int pos) {
	tsNodo *curr = l->lista;
	tsNodo *temp = NULL;
	if(pos == 0) {
		SuprimirPrimerElemento(l);
		--(l->n);
		return 1;
	}
	if(pos == l->n) {
		SuprimirUltimoElemento(l);
		--(l->n);
		return 1;
	}
	else {
		for (int i = 0; i < pos-1; ++i) {
			if(curr->sig == NULL)
				return 0;
			curr = curr->sig;
		}
		temp = curr->sig;
		curr->sig = temp->sig;
		free(temp);
		--(l->n);
		return 1;
	}
}

/*Retorna la longitud de la lista.*/
int LongitudLista(Lista_T l) {
	return l.n;
}

/*Devuelve el dato de la posición pos. Si no existe, devuelve una posicion negativa (-1)*/
int DevolverDatoPosicion(Lista_T l, int pos) {
	tsNodo *act;
	if (pos >= 1 && pos <= LongitudLista(l)) {
		act = l.lista;
		for (int i = 0; i < pos; ++i)
			act = act->sig;
		return (act->dato);
	}
	else {
		printf("Posicion fuera de rango.\n");
		return -1;
	}
}

/*Se hace apuntar l->lista al elemento siguiente al primero, y luego se libera este.*/
void SuprimirPrimerElemento(Lista_T* l) {
    tsNodo *temp;
	if((temp = l->lista) == NULL) {
		puts("Error: No se puede eliminar datos (no hay primer elemento).");
		return;
	}
	l->lista = (l->lista)->sig;
	free(temp);
}

/*Itera hasta el penultimo elemento, libera el ultimo y asigna NULL al que ahora es el ultimo elemento.*/
void SuprimirUltimoElemento(Lista_T *l) {
	tsNodo *temp = l->lista;
	while ((temp->sig)->sig != NULL) {
		temp = temp->sig;
	}
	free(temp->sig);
	temp->sig = NULL;
}

void Quits() {
	puts("Error: Memoria insuficiente.");
	exit(1);
}

void Menu(Lista_T *list) {
	int op = 0, primero = 1, result, num, bus_op;
	char op_elim;
	do {
		puts("Que desea realizar?");
		puts("1)-Agregar dato\n2)-Eliminar dato\n3)-Imprimir lista\n4)-Buscar dato\n0)-Salir\n");
		if(!scanf("%d", &op)) {
			puts("Error de input.");
			exit(-1);
		}
		switch(op) {
			case 0: break;
			case AGREGAR:
				puts("Ingrese el numero que desea agregar:");
				if(!scanf("%d", &num)) {
					puts("Error de input.");
					exit(-1);
				};
				if(!primero)
					result = InsertarUltimo(list, num);
				else {
					primero = 0;
					result = InsertarPrimero(list, num);
				}
				if(result)
					printf("El dato %d fue agregado en la posicion %d\n", num, list->n);
				else
					puts("Error: No se pudo agregar el dato.");
				break;
			case ELIMINAR:
				printf("a).Por dato\nb).Por posicion\n");
				if(!scanf(" %c", &op_elim)) {
					puts("Error de input.");
					exit(-1);
				}
				if(op_elim == 'a' || op_elim == 'A') {
					puts("Ingrese el dato que desea eliminar:");
					if(!scanf("%d", &num)) {
						puts("Error de input.");
						exit(-1);
					}
					if(SuprimirDato(list, num))
						printf("Dato \"%d\" eliminado.\n", num);
					else
						puts("El dato ingresado no existe en la lista.");
				}
				else if(op_elim == 'b' || op_elim == 'b') {
					puts("Ingrese la posicion del nodo que desea eliminar:");
					if(!scanf("%d", &num)){
						puts("Error de input.");
						exit(-1);
					}
					if(SuprimirNodo(list, num))
						printf("El nodo en la posicion %d ha sido eliminado.\n", num);
					else
						puts("Posicion invalida.");
				}
				break;
			case IMPRIMIR:
				if(RecorrerLista(*list) != 1)
					puts("La lista esta vacia.");
				break;
			case BUSCAR:
				puts("Ingrese la posicion del dato:");
				if(!scanf("%d", &bus_op)) {
					puts("Error de input.");
					exit(-1);
				}
				num = DevolverDatoPosicion(*list, bus_op);
				if(num != -1)
					printf("El numero de la posicion \"%d\" es: %d\n", bus_op, num);
				break;
			default:
				puts("Error: Opcion invalida.");
		}
	} while (op != 0);
}

#endif