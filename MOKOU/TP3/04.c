/*4) Se desea implementar una lista de enteros. Se pide obtener la cantidad de espacio de memoria utilizado para
las implementaciones:
	1. La lista tiene 100 elementos y se implementa con punteros.
	2. La lista tiene 100 elementos y se tiene como precondición que la cota superior de elementos de la lista es
	de 100 elementos. Se implementa con arreglos.
Indique ventajas y desventajas de cada implementación. Indique qué implementación utilizaría y justifique su
respuesta.*/


/*
Ambos métodos utilizan (a priori) la misma memoria, pero el primero puede crecer dinámicamente (al estar en el heap) por
lo que puede ser más eficiente en su uso de memoria,, mientras que el segundo no (además de que al estar en stack no puede
crecer fuera del limite impuesto por el OS).*/