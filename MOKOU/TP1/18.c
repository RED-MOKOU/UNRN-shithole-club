Dada la siguiente lista:
a)- {47, 3, 21, 32, 56, 92}
Después de dos pasadas de un algoritmo de ordenacion, el arreglo ha quedado dispuesto así:
b)- {3, 21, 47, 32, 56, 92}
¿Qué algoritmo de ordeancion se está utilizando (seleccion, burbuja o insercion)? Justifique la respuesta.

---
Respuesta: Podria estarse usando o el algoritmo de seleccion o el de insercion (dado que ambos llegan al mismo vector (b) luego de 3 pasadas).
El algoritmo de burbuja llegaria al vector b) en una sola pasada, por lo que no puede ser el metodo utilizado.

--------
Por seleccion:

0)- {47, 3, 21, 32, 56, 92} = a)

1)- {47, |3|, 21, 32, 56, 92}
Se recorre toda la lista desde la posicion 0 y se encuentra que 3 es el numero de menor valor. Se hace swap con el valor de la posicion 0.
Ahora, el vector se ve asi: {3, 47, 21, 32, 56, 92}

2)- {3, 47, |21|, 32, 56, 92}
Se recorre toda la lista desde la posicion 1 y se encuentra que 21 es el numero de menor valor. Se hace swap con la posicion 1.
Ahora, el vector se ve asi: {3, 21, 47, 32, 56, 92}

3)- {3, 21, 47, 32, 56, 92} = b)

El vector esta ordenado igual que b).
--------
Por insercion:

0)- {47, 3, 21, 32, 56, 92} = a)

1)- {47, |3|, 21, 32, 56, 92}
Se compara 3 con 47, se encuentra menor que este, se corre el 47 un lugar a la derecha y se asigna el 3 al primer lugar.
Ahora el vector se ve asi: {3, 47, 21, 32, 56, 92}

2)- {3, 47, |21|, 32, 56, 92}
Se compara el 21 con 47, se encuentra menor que este, se corre el 47 un lugar a la derecha y se le asigna el 3 al segundo lugar.
Ahora, el vector se ve asi: {3, 21, 47, 32, 56, 92}

3)- {3, 21, 47, 32, 56, 92} = b)

El vector esta ordenado igual que b).