#include <stdio.h>

int main(int argc, char** argv[])
{
	int top = -1000;
	int bttm = 1000;
	int sum = 0;
	int cnt = 0; //counter
	int a = 0;

	while(a != -1){
		printf("Input number: "); scanf("%d", &a);
		if(a == -1) break; //otherwise -1 is added to the total and the thing fucks up. Dunno, man, compiler is autistic.
		top = a > top ? a : top;
		bttm = a < bttm ? a : bttm;
		sum += a; cnt++;
	};
    puts("----");
    printf("Max: %d\nMin: %d\nTotal inputted numbers: %d\n", top, bttm, cnt);
	printf("Sum: %d\nAverage: %.2f", sum, (float)(sum/cnt));

	return 0;
}
