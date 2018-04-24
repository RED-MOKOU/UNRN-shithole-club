/*8) Escriba un programa para generar matrices cuadradas de enteros (el usuario introduce la dimension por teclado
y todas las matrices generadas tienen el mismo tamaño). El programa reserva memoria todas las matrices
requeridas. Se pide implementar funciones para inicializar matrices: con numeros aleatorios entre 1 y 9, matriz
simetrica con numeros aleatorios entre 1 y 9, matriz identidad. Luego, implemente funciones para imprimir una
matriz y funciones para resolver la suma, resta, multiplicacion y transpuesta de matrices. En el codigo de la
funcion main() se debe resolver A * I = A, donde I es la matriz identidad y A es una matriz cualquiera. Mostrar
por pantalla las matrices para verificar esta igualdad. */

#include "basiclib.h" //stdio, stdlib, time, Quits()
#define MAX_VALUE 10

/*Imprime la matriz m*/
void PrintMat(int *m, int dim) {
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j)
				printf("%d ", m[i*dim+j]);
	puts("");
	}
	printf("\n");
}

int ReturnIndex(int i, int j, int dim) {
	if (i <= j)
		return i * dim - (i - 1) * i / 2 + j - i;
	else
		return j * dim - (j - 1) * j / 2 + i - j;
}

/*Genera una matriz identidad de dimension dim*/
int* GenIden(int dim) {
	int *mat = NULL;
	mat = (int*)malloc((dim*dim)*sizeof *mat);
	if(mat == NULL)
		Quits();
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j)
			mat[i*dim+j] = (i == j) ? 1 : 0;
	}
	return mat;	
}

/*La matriz simetrica es guardada en un array 1D (se guarda solo la mitad superior con respecto a la diagonal).
El indice en el vector 1D es determinado por la funcion ReturnIndex(). El numero de elementos en el vector simetrico
de una matriz de dimension DIM es: (DIM^2-DIM)/2+DIM*/
int* GenSim(int dim) {
	int *aux = NULL, *out = NULL;
	int aux_dim = (dim*dim-dim>>1)+dim;
	aux = (int*)malloc(aux_dim*sizeof *aux);
	out = (int*)malloc((dim*dim)*sizeof *out);
	if(aux == NULL || out == NULL)
		Quits();

	/*Primero se almacenan los datos en el vector 1D*/
	for (int i = 0; i < aux_dim; ++i) {
		for (int j = 0; j < aux_dim; ++j)
			aux[ReturnIndex(i, j, dim)] = rand()%MAX_VALUE;
	}

	/*Luego son copiados a una matriz 2D*/
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j)
			out[i*dim+j] = aux[ReturnIndex(i, j, dim)];
	}
	free(aux);
	return out;	
}

/*Genera una matriz cuadrada de numeros aleatorios de dimension dim*/
int* GenMat(int dim) {
	int *mat = NULL;
	mat = (int*)malloc((dim*dim)*sizeof *mat);
	if(mat == NULL)
		Quits();
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j)
			mat[i*dim+j] = rand()%MAX_VALUE;
	}
	return mat;	
}

/*Suma de matrices: C=A+B*/
int* Addition(int* A, int* B, int dim) {
	int *C = NULL;
	C = (int*)malloc((dim*dim)*sizeof *C);
	if(C == NULL)
		Quits();
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			C[i*dim+j] = A[i*dim+j] + B[i*dim+j];
		}
	}
	return C;
}

/*Resta de matrices: C=A-B*/
int* Substraction(int* A, int* B, int dim) {
	int *C = NULL;
	C = (int*)malloc((dim*dim)*sizeof *C);
	if(C == NULL)
		Quits();
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j) {
			C[i*dim+j] = A[i*dim+j] - B[i*dim+j];
		}
	}
	return C;	
}

/*Multiplicacion de matrices: C=AB*/
int* Multiplication(int* A, int* B, int dim) {
	int *C = NULL;
	C = (int*)malloc((dim*dim)*sizeof *C);
	if(C == NULL)
		Quits();
	for(int i = 0;i < dim; ++i) {
		for(int j = 0;j < dim; ++j) {
			C[i*dim+j] = 0;
			for(int k = 0;k < dim; ++k)
				C[i*dim+j] += A[i*dim+k]*B[k*dim+j];
		}
	}
	return C;
}

/*Transpuesta de una matriz: C'*/
int* Transpose(int* A, int dim) {
	int *T = NULL;
	T = (int*)malloc((dim*dim)*sizeof *T);
	if(T == NULL)
		Quits();
	for (int i = 0; i < dim; ++i) {
		for (int j = 0; j < dim; ++j)
			T[i*dim+j] = A[j*dim+i];
	}
	return T;
}

int main() {
    srand(time(NULL));
	int *A,*B,*I,*C = NULL;
	int dim = 0, op = 0;
	char m = 0;
	puts("Ingrese dimension de las matrices:");
	scanf("%d", &dim);
	A = GenMat(dim);
	B = GenSim(dim);
	I = GenIden(dim);
	puts("A:");
	PrintMat(A, dim);
	puts("B:");
	PrintMat(B, dim);
	puts("I:");
	PrintMat(I, dim);
	do {
		printf("Que operacion desea realizar?\n
		0-)Salir\n
		1-)Suma\n
		2-)Resta\n
		3-)Multiplicacion\n
		4-)Transpuesta\n");
		scanf("%d", &op);
		switch(op) {
			case 1:
				printf("a). A+B\nb). B+A\n");
				scanf(" %c", &m);
				if(m == 'A' || m == 'a')
					C = Addition(A, B, dim);
				else if(m == 'B' || m == 'b')
					C = Addition(B, A, dim);
				else {puts("Error: Opcion invalida."); exit(1);}
				PrintMat(C, dim);
				break;
			case 2:
				printf("a). A-B\nb). B-A\n");
				scanf(" %c", &m);
				if(m == 'A' || m == 'a')
					C = Addition(A, B, dim);
				else if(m == 'B' || m == 'b')
					C = Substraction(B, A, dim);
				else {puts("Error: Opcion invalida."); exit(1);}
				PrintMat(C, dim);	
				break;
			case 3:
				printf("a). AB\nb). BA\nc). AI\nd). BI\n");
				scanf(" %c", &m);
				switch(m) {
					case 'a':
						C = Multiplication(A, B, dim);
						PrintMat(C, dim);
						break;
					case 'b':
						C = Multiplication(B, A, dim);
						PrintMat(C, dim);
						break;
					case 'c':
						C = Multiplication(A, I, dim);
						PrintMat(C, dim);
						break;
					case 'd':
						C = Multiplication(B, I, dim);
						PrintMat(C, dim);
						break;
					default: puts("Error: Opcion invalida."); exit(1);
				}
				break;
			case 4:
				puts("a). Transpuesta de A\nb). Transpuesta de B\n");
				scanf(" %c", &m);
				if(m == 'A' || m == 'a')
					C = Transpose(A, dim);
				else if(m == 'B' || m == 'b')
					C = Transpose(B, dim);
				else {puts("Error: Opcion invalida."); exit(1);}
				PrintMat(C, dim);
				break;
			default: break;
		}
	} while(op < 5 && op > 0);
	free(A);
	free(B);
	free(I);
	free(C);
	return 0;
}
