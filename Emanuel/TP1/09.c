/*9) Dado el siguiente código, realizar un diagrama donde se muestre por cada instrucción lo que sucede con los
contenidos de las variables, suponiendo que la variable “a” se encuentra en la direccón 5858 y la variable “b”
en la dirección de memoria 9000.
int *dir_a, *dir_b;
int a, b;
a = 3;
dir_a = &a;
dir_b = &b;
*dir_b = *dir_a;*/

int *dir_a, *dir_b; //Declaracion de variables como pointer (que, por el momento, no apuntan a ninguna variable importante para el programa)
int a, b; //Declaracion de variables int, la direccion de "a" es: 5858, y la de "b" es: 9000
a = 3; //Se asigna el valor 3 a la variable "a" (direccion 5858)
dir_a = &a; //Se le asigna el valor 5858 al pointer dir_a (Se lo hace apuntar a la direccion en la que esta alojada la variable "a")
dir_b = &b; //Ditto, pero con la variable "b" en la direccion 9000
*dir_b = *dir_a; //Se le asigna el valor de "a" a "b" mediante desreferenciacion de pointers.
				 //(A la variable alojada en la direccion 9000 se le asigna el valor de la variable en la direccion 5858)