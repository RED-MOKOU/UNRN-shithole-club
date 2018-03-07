#include <stdio.h>
#define MAX_COL 10
#define MAX_ROW 30 //if your name is longer than 30 characters you are a sub human.

/* I forgot how fucking pointers work lol
void PrintNames( char *grid[MAX_COL][MAX_ROW]) {

	signed int x;
	for(x = 0; x < MAX_COL; x++) {
		printf("%s\n", *grid[x]);
	}
}

void Mayus( char *namevector[MAX_COL][MAX_ROW]) {

}
*/
int main(int argc, char** argv[])
{
	char names[MAX_COL][MAX_ROW];
	signed int cnt = 0, index = 0, x;

	do
	{
		puts("Input number:");
		scanf("%s",&names[index]);
		index++; cnt++;
	} while(cnt < MAX_COL);
    puts("---");
//	Mayus(names);
//	PrintNames(names);
	for(x = 0; x < MAX_COL; x++) {
		if((names[x][0] >= 97) && (names[x][0] <= 122))
			names[x][0] -= 32;
        printf("%s\n", names[x]);
	}
	return 0;
}
