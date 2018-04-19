/* UNRN PyA - Jose Emanuel Suez

10) Vector de vectores: realizar un programa que lea un valor. Dicho valor especifica la cantidad de elementos
de un arreglo de vectores de enteros. Para cada posicion del vector, pedir la dimension del subvector y alocar
memoria para dicho vector. Inicializar toda la estructura y luego, imprimir los datos del vector. Desalocar
memoria de forma correcta. Notar que es necesario mantener la informacion de la dimension de cada uno de
los subvectores. Una forma de realizarlo es que cada subvector sea una estructura de la forma:

typedef struct {
    int n;
    int *vector;
} Vector_T;

donde el campo n de la estructura es la dimensión del vector. El puntero a enteros es el arreglo dinámico con n
posiciones.*/

#include <basiclib.h> //stdio, stdlib, time, Quits()
#define MAX_VALUE 10

typedef struct {
	int n;
	int *vector;
} Vector_T;

/*Imprime el tamaño n de cada subvector y su direccion*/
void PrintfInfo(Vector_T *v, int dim) {
	puts("---");
	for (int i = 0; i < dim; ++i) {
		printf("nº: %d\ndireccion del vector: %p", (v+i)->n, (v+i)->vector);
		puts("---");
	}
}

/*Libera cada subvector y luego el vector de vectores*/
void FreeMem(Vector_T *Vector, int dim) {
	for (int i = 0; i < dim; ++i) {
		free((Vector+i)->vector);
	free(Vector);
}

/*Inicializa los subvectores con valores aleatorios*/
void InitVec(Vector_T *R, int dim) {
	for (int i = 0; i < dim; ++i) {
	    (R+i)->vector = NULL;
		(R+i)->vector = (int*)malloc((R+i)->n*sizeof(int));
		if((R+i)->vector == NULL)
				Quits();
		for (int j = 0; j < (R+i)->n; ++j) {
			*(((R+i)->vector)+j) = rand()%MAX_VALUE;
			printf("Vector %d, subvector %d: %d ", i, j, *(((R+i)->vector)+j));
		}
		puts("");
	}
}

/*Lee los tamaños de los subvectores y luego los inicializa mediante InitVec()*/
Vector_T *Leer(int dim) {
	Vector_T *V = NULL;
	if(V == NULL)
		Quits();
	puts("Ingrese el tamaño de los %d subvectores:");
	for (int i = 0; i < dim; ++i) {
		printf("Tamaño del vector nº %d: ", i+1);
		scanf("%d", &(V+i)->n);
	}
	InitVec(V, dim);
}

int main() {
	Vector_T *v = NULL;
	int dim;
	puts("Ingrese el tamaño del vector:");
	scanf("%d", &dim);
	v = Leer(dim);
	PrintfInfo(v, dim);
	FreeMem(v, dim);
	return 0;
}