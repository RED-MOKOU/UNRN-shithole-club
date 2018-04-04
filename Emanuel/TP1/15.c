/*15) Implemente la funcion exchangeInt() entre 2 variables enteras. Implemente la funcion exchangeCom()
entre dos complejos.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int i, r;
} tsComp;

void InitInt(int* a, int* b) {
	*a = rand()%10+1;
	*b = rand()%10+1;
	printf("a=%d\nb=%d\n", *a, *b);
}

void InitComp(tsComp *a, tsComp *b) {
	a->r = rand()%10+1;
	a->i = rand()%10+1;
	b->r = rand()%10+1;
	b->i = rand()%10+1;
	printf("a=[%d,%d]\nb=[%d,%d]\n", a->r, a->i, b->r, b->i);
}

void exchangeInt(int* x, int* y) {
	int aux;
	*x = aux;
	*x = *y;
	*y = aux;
}

void exchangeCom(tsComp *x, tsComp *y) {
	tsComp aux;
	*x = aux;
	*x = *y;
	*y = aux;
}

int main() {
	srand(time(NULL));
	int a, b;
	tsComp c, d;
	InitInt(&a, &b);
	InitComp(&c, &d);
	exchangeInt(&a, &b);
	exchangeCom(&c, %d);
	puts("Luego del cambio:");
	printf("a=%d\nb=%d\n", a, b);
	printf("a=[%d,%d]\nb=[%d,%d]\n", c.r, c.i, d.r, d.i);
	return 0;
}