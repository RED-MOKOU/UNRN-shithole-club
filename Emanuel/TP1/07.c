#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

void InitArr(int arr[N]) {
	int i;
	for(i = 0; i < N; i++)
		arr[i] = rand()%100+1;
}

void Compare2(int arr[N], int num) {
	int i;
	for(i = 0; i < N; i++) {
		if(arr[i] == num)
			printf("\nNumber %d has been found in array in position: %d", num, i);
	}
}

void Compare(int arr[N], int num) {
	int i = 0;
	while (arr[i] != num) {
			i++;
		}
	printf("\nNumber %d has been found in array in position: %d", num, i);
}

void PrintArr(int arr[N]) {
	int i;
	for(i = 0; i < N; i++) {
		printf("%3d ", arr[i]);
		if(i%30 == 0)
			printf("\n");
	}
	puts("---");
}

int main(int argc, char** argv) {

	srand(time(NULL));
	int arr[N], num;
	InitArr(arr);
	PrintArr(arr);
	printf("Input number: ");
	scanf("%d", &num);
//	Compare(arr, num);
	Compare2(arr, num);

	return 0;
}
