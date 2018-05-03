/*3) Responda:
(a) ¿Cuál de las 2 implementaciones anteriores es más conveniente? ¿Qué aspectos tendría en cuenta para optar
por una de las dos implementaciones?
(b) Cuál de las 2 implementaciones elije si:
	(I) No se sabe la cantidad de elementos de la lista. No es posible acotar una posible longitud de la lista.
	(II) Se realizan muchas operaciones InsertarPrimero(), InsertarUltimo() y SuprimirDato().
	(III) Sobre todo, se realizan operaciones devolverDatoPosicion() sobre la lista.
*/


/*a)- Depende del contexto. La implementación mediante arrays es más eficiente en el uso de memoria y en la obtención de valores de una posición
específica, pero por otra parte requiere más tiempo de ejecución y por lo tanto no es óptima para utilizar con listas con una gran cantidad de elementos.
Por otro lado, el TAD lista requiere más memoria y no puede accederse a un elemento mediante su posición (hay que recorrer todos los elementos anteriores),
pero el tiempo de ejecución para el ingreso y eliminación de datos se simplifica enormemente.

b)
I). TAD lista (la lista puede crecer indefinidamente y ser muy grande como para que el manejo mediante arrays sea efectivo).
II).TAD lista (mejor manejo de inserción y eliminación de elementos en una lista).
III) array (es más fácil dereferenciar array[pos] que recorrer la lista hasta la posición deseada).*/