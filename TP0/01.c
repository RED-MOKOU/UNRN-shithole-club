/*This stupid program takes two numbers and returns the biggest one. Why did I make it?
Because the teacher is nuts.*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a,b;
	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%d", a>b ? a : b); //and that's it, you're an fagit
	return 0;
}
