#include <stdio.h>

int main(int argc, char const *argv[])
{
	int top = -1000;
	int bttm = 1000;
	int sum = 0;
	int cnt = 0; //counter
	int a = 0;

	while(a != -1){
		printf("Ingrese numero: "); scanf("%d", &a);
		if(a == -1) break; //otherwise -1 is added to the total and the thing fucks up. Dunno, man, compiler is autistic.
		top = a > top ? a : top;
		bttm = a < bttm ? a : bttm;
		sum += a; cnt++;
	};
    puts("----");
    printf("El maximo es: %d\nEl minimo es: %d\nEn total, hubo %d numeros.\n", top, bttm, cnt);
	printf("La suma total de numeros es: %d\nEl promedio es: %.2f", sum, (float)(sum/cnt));

	return 0;
}
