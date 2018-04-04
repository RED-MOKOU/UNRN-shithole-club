La diferencia entre el algoritmo de insercion y el de seleccion radica en la forma en que se manipulan los elementos para
ordenarlos.

El algoritmo por insercion analiza todos los elementos de una lista de n elementos desde la segunda posicion hasta n, mediante un indice i.
En cada itineracion, se compara el elemento en la posicion i con los que estaban antes que el, los cuales se desplazan un lugar hacia la derecha.
Finalmente, al hallar el lugar correcto, el elemento que se encontraba en i se inserta en el lugar que le corresponde (el cual esta "vacio" debido
al corrimiento).

Lista de elementos: A C B D, ordenamiento de menor a mayor.

1)- A|C|B D
Se analiza C (posicion 2). Se lo compara con A, y dado que C va despues que A, no sucede nada.

2)- A C|B|D
Se analiza B (posicion 3). Se encuentra menor que C, y se mueve todos los elementos desde la posicion 2 hasta B un lugar hacia la derecha.
Luego, se inserta el elemento.

a) A C|B|D	// Se quita |B| de la lista
b) A -> C D	//Se realiza el corrimiento
c) A B C D	//Se inserta el elemento B en la posicion 2.

---------

El algoritmo de seleccion, por otra parte, recorre la lista entera buscando el elemento mas pequeño (o grande) y lo coloca en la posicion 0 del vector,
y tambien le asigna el elemento que estaba en 0 a la posicion donde estaba el elemento mas pequeño/grande (efectivamente, un swap de valores).
Luego, sigue buscando a partir de la posicion 1 hasta n, y cambia el valor de interes a la posicion 1. Esto se repite n-1 veces.

Lista de elementos: B C D A, ordenamiento menor a mayor.

1)- B C D A
Se recorre el vector desde 0 y se encuentra que el valor "A" es el menor.
Se le asigna el valor "A" la posicion 0.
Se le asigna el valor "B" a la posicion 3.

2) A C D B
Se recorre el vector desde 1 y se encuentra que el valor "B" es el menor.
Se le asigna el valor "B" la posicion 1.
Se le asigna el valor "C" a la posicion 3.

3) A B D C
Se recorre el vector desde 2 y se encuentra que el valor "C" es el menor.
Se le asigna el valor "C" la posicion 2.
Se le asigna el valor "D" a la posicion 3.

4) A B C D
La lista esta ordenada.
