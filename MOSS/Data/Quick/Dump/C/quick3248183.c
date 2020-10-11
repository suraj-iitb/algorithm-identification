/* ALDS1_6_C: QuickSort */
/* 20181121 AOJ */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define N 100000

typedef struct {
	int order;
	char suit;
	int value;
} Card;

int partition(Card* A, int p, int r);
void quickSort(Card* A, int p, int r);
void swap(Card* x, Card* y);
int stableJudge(Card* A, int n);

int main(void) {
	Card* A = (Card *)malloc(sizeof(Card) * N);
	int n;
	int i = 0;
	//char S[2];

	scanf("%d", &n);
	getchar();
	while(i < n) {
		//scanf("%s %d", S, &A[i].value);
		//A[i].suit = S[0];
		scanf("%c %d", &A[i].suit, &A[i].value);
		getchar();
		A[i].order = i + 1;
		i++;
	}

	quickSort(A, 0, n - 1);

	if(stableJudge(A, n)) {
		puts("Stable");
	} else {
		puts("Not stable");
	}
	
	for(i = 0; i < n; i++) {
		//printf("%2d %c %d\n", A[i].order, A[i].suit, A[i].value);
		printf("%c %d\n", A[i].suit, A[i].value);
	}

	return 0;
}

void quickSort(Card *A, int p, int r) {
	int q;

	if(p < r) {
		q = partition(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

int partition(Card *A, int p, int r){
	int i, j;

	i = p - 1;
	for(j = p; j < r; j++) {
		if(A[j].value <= A[r].value) {
			i++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[++i], &A[r]);

	return i;
}

void swap(Card* x, Card* y) {
	Card temp = *x;
	*x = *y;
	*y = temp;
}

int stableJudge(Card* A, int n) {
	int i, j;
	
	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
			if(A[i].value == A[j].value && A[i].order > A[j].order) {
				return 0;
			}
		}
	}

	return 1;
}
