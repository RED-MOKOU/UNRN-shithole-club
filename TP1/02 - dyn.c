#include <stdio.h>
#include <stdlib.h>
#include <time.h>
     
int* InitArr(int row, int col) {
     
    signed int i, max = row*col;
    int* arr = malloc(sizeof(int)*max);
    int* cursor = arr;
    for( i = 0; i < max; i++ ) {  
        *cursor = rand()%11+20;
        cursor++;
    }
    return arr;
}
     
void Print(int* address, int row, int col) {

    int* p = address;
    signed int i, j;
    for( i = 0; i < row; i++ ) {
        for( j = 0; j < col; j++ )
            printf("%2d ", p[i*col+j]);
        printf("\n");
    }
}
     
int main(int argc, char** argv)
{
    srand(time(NULL));
    signed int a, b;
       
    puts("Input matrix dimensions (AxB)");
    scanf("%d %d", &a, &b);
    if(a < 0 || b < 0) return 1; //don't do this please.
     
    int* matrix = InitArr(a, b);
    Print(matrix, a, b);
    free(matrix);
     
    return 0;
}
