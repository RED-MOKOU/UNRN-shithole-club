/*20) Un arreglo contiene los elementos indicados a continuación. Utilizando el algoritmo de búsqueda binaria,
trazar las etapas necesarias para encontrar el número 88.
{8, 13, 17, 26, 44, 56, 88, 97}
Igual búsqueda pero para el número 20.*/

/*Para el valor 88 hay 3 etapas.
Primera:
bajo = 0, alto = 7
central = 3
valorcentral = 26
->bajo = 3 + 1 = 4

Segunda:
bajo = 4, alto = 7
central = 5
valorCentral = 56
->bajo = 5+1 = 6

Tercera:
bajo = 6, alto = 7
central = 6
valorCentral = 88 --> valor buscado

Para el valor 20 tambien tuvo 3 etapas, que fueron las necesarias para confirmar que el valor no estaba dentro del array.*/

#include <stdio.h>
#define SIZE 8
#define BUSCADO 88 //20

int etapas = 0;

int BusquedaBin(int lista[SIZE], int n, int clave) {
	int central, bajo = 0, alto = n-1;
	int valorCentral;
	while (bajo <= alto) {
		etapas++;
		central = (bajo + alto) / 2;
		valorCentral = lista[central];
		if (clave == valorCentral)
			return central;
		else if (clave < valorCentral)
			alto = central - 1;
		else
			bajo = central + 1;
	}
	return 0;
}

int main() {

	int arr[] = {8, 13, 17, 26, 44, 56, 88, 97};
	int posicion = BusquedaBin(arr, SIZE, BUSCADO);
	if(posicion)
		printf("El numero buscado es: %d, el cual fue hallado en la posicion: %d\nLa cantidad de etapas fue de: %d", BUSCADO, posicion, etapas);
	else
		printf("El numero %d no se encuentra en el array. Se realizaron %d etapas para confirmar esto.", BUSCADO, etapas);
	return 0;
}