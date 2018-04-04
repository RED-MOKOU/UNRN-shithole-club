/*10) Escriba un programa en C que incluya las siguientes instrucciones de declaración:
int num, cuenta;
long fecha;
float pendiente;
double potencia;

a) Utilice el operador de dirección (&) y la función printf() para mostrar las direcciones correspondientes a
cada variable.
b) Utilice la función sizeof() para determinar el tamaño de cada variable.
c) Al código anterior, agregue las siguientes declaraciones:
int *p_num;
long *p_fecha;
float *p_pendiente;
double *p_potencia;

¿Qué imprime cada una de las siguientes líneas? Explique en cada caso lo que imprime y justifique:
printf("Cantidad de bytes de ’p_num’: %ld y contenido de p_num %ld \n", sizeof(p_num), sizeof(*p_num));
printf("Cantidad de bytes de ’p_potencia’: %ld y contenido de p_potencia: %ld \n", sizeof(p_potencia), sizeof(*p_potencia));
printf("Cantidad de bytes de ’p_pendiente’: %ld y contenido de p_pendiente: %ld \n", sizeof(p_pendiente), sizeof(*p_pendiente));
*/

#include <stdio.h>

int main(int argc, char** argv)
{
	int num, cuenta;
	long fecha;
	float pendiente;
	double potencia;
	int *p_num;
	long *p_fecha;
	float *p_pendiente;
	double *p_potencia;
	printf("La direccion de num es: %08x, y su tamaño es: %u bytes \n", &num, sizeof num);
	printf("La direccion de cuenta es: %08x, y su tamaño es: %u bytes \n", &cuenta, sizeof cuenta);
	printf("La direccion de fecha es: %08x, y su tamaño es: %u bytes \n", &fecha, sizeof fecha);
	printf("La direccion de pendiente es: %08x, y su tamaño es: %u bytes \n", &pendiente, sizeof pendiente);
	printf("La direccion de potencia es: %08x, y su tamaño es: %u bytes \n", &potencia, sizeof potencia);
	puts("---");
	//Las siguientes lineas imprime el tamaño que ocupa el pointer, y luego el tamaño de la variable a la que apunta.
	printf("Cantidad de bytes de ’p_num’: %ld y contenido de p_num %ld \n", sizeof(p_num), sizeof(*p_num));
	printf("Cantidad de bytes de ’p_potencia’: %ld y contenido de p_potencia: %ld \n", sizeof(p_potencia), sizeof(*p_potencia));
	printf("Cantidad de bytes de ’p_pendiente’: %ld y contenido de p_pendiente: %ld \n", sizeof(p_pendiente), sizeof(*p_pendiente));
	return 0;
}