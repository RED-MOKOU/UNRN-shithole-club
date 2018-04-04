/*14) Considere el pasaje de parámetros por valor y por referencia. Determinar qué imprime el siguiente programa.
a)- ¿Qué es lo que se está pasando como argumente en el llamado:
funcion2(&a, &b);
b)- ¿Qué es lo que se especifica en el encabezamiento de la funcion2() con respecto a los parámetros llamados x
e y?*/

/*El programa crea las variables (a, b), las imprime (valores: 3, 10), y luego las manda a funcion1(), la cual crea nuevas variables (x, y),
en donde se las opera. Dentro de funcion1(), las variables (x, y) se imprimen (valores: 4, 9) luego de ser operadas, y son liberadas.
Luego, el programa vuelve a imprimir las variables (a, b) en main() (y dado que no sufrieron ningun cambio, siguen teniendo como valor 3, 10).
Mas tarde, se envian las direcciones de las variables (a, b) a funcion2(), donde se opera mediante dereferenciacion de los pointers (*x,*y) a las variables
(a, b) (valores: 4, 9), y se las imprime dentro de funcion2().
Luego, se las vuelve a imprimir en main(), donde efectivamente vuelve a imprimirse el valor que se obtuvo en funcion2() (4, 9).

a)- Lo que se pasa en el llamado funcion2(&a,&b) es la direccion de las variables a, b en la memoria.
b)- En el encabezamiento de la funcion2(), se especifica que las variables de entrada de la funcion son pointers, los cuales son variables que
apuntan a direcciones en memoria, y por lo tanto el valor que toman es el valor de una direccion en memoria (&a).*/

#include <stdio.h>
int funcion1(int x, int y)
{
	x = x + 1;
	y = y - 1;
	printf("Dentro de funcion1, x = %d, y = %d ", x, y);
	return 0;
}
int funcion2(int *x, int *y)
{
	*x = *x + 1;
	*y = *y - 1;
	printf("Dentro de funcion1, x = %d, y = %d ", *x, *y);
	return 0;
}
int main()
{
	int a, b;
	a = 3;
	b = 10;
	printf("Antes de llamar a funcion1, a = %d, b = %d ", a, b);
	funcion1(a,b);
	printf("Despues de llamar a funcion1, a = %d, b = %d ", a, b);
	printf("Antes de llamar a funcion2, a = %d, b = %d ", a, b);
	funcion2(&a,&b);
	printf("Despues de llamar a funcion2, a = %d, b = %d ", a, b);
	return 0;
}