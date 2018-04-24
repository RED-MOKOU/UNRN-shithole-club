/*5) Explique que realiza el siguiente programa. Agregue comentarios explicando cada parte del codigo.*/

/*-----
El programa pregunta por la dimension para crear vector de floats mediante memoria dinamica,
le pide la memoria al OS mediante calloc (la cual inicializa todos los valores a 0),
y luego le pide al usuario que ingrese los valores de dicho vector.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
	/*Declaracion de variables.*/
	float *pf = NULL;
	int i, num;

	/*Ingreso de la dimension del vector*/
	do {
		printf("Ingrese la dimensión del vector");
		scanf("%d", &num);
	} while(num < 1); //Nota: No tiene sentido usar un loop para esto.
	
	pf = (float*) calloc(num, sizeof(float)); //Se pide num espacios de memoria, cada uno de tamaño de un sizeof(float). Se los inicializa en 0.
	if(pf == NULL) { printf("Error en la asignacion de memoria"); exit(-1); } //Si no hay memoria disponible, se cierra el programa.

	/*Ingreso de los valores del vector.*/
	printf("Ingrese %d valores", num);
	for(i = 0; i < num; i++)
		scanf("%f", &pf[i]);

	free(pf); //Se libera la memoria utilizada en el heap.
	return 0;
}
