#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int selectionSort(int R[], int N);

void swap(int *a, int *b);

int main(void) {

	int N;
	scanf("%d\n", &N);//半角スペースで区切ることができる。

	int R[100];

	int t,k,x;
	for (t = 0; t < N ; t++) {
		scanf("%d", &R[t]);
	}
	
	x = selectionSort(R, N);
	
	for (k = 0; k < N; k++) {
        if(k > 0){printf(" ");}
	printf("%d", R[k]);
	}
	printf("\n%d\n",x);

	return 0;
	
	}

int selectionSort(int R[],int N) {
	int i,j,minj;
	int count = 0;
	for (i = 0; i < N-1; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (R[j] < R[minj]) {
				minj = j;
			}
		}
		swap(&R[i], &R[minj]);
		if (i != minj) {
			count++;
		}
	}
	return count;
}

void swap(int *a, int *b) {
	int k;
	k = *a;
	*a = *b;
	*b = k;
}
