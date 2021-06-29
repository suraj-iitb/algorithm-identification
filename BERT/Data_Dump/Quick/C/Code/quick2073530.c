#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	char m;
	int num;
	int index;
}card;

int partition(card A[], int p, int r);
void quicksort(card A[], int p, int r);
int isStable(card A[], int n);

int main() {
	int r, n, i;
	card *Card;
	Card = (card *)malloc(sizeof(card) * 100000);
	scanf("%d", &n);
	r = n-1;
	for (i = 0; i < n; i++) { scanf("%1s %d", &Card[i].m, &Card[i].num); Card[i].index = i; }
	quicksort(Card, 0, r);
	if (isStable(Card,n))puts("Stable"); else puts("Not stable");
	for (i=0; i < n; i++) printf("%c %d\n", Card[i].m,Card[i].num);
	free(Card);
	return 0;
}

int partition(card A[], int p, int r){
	int i,x,j;
	card tmp;
	x = A[r].num;
	i = p-1;
	for (j = p; j <= r; j++) {
		if (A[j].num <= x) {
			i++;
			tmp = A[i]; A[i] = A[j]; A[j] = tmp;
		}
	}
	return i;
}

void quicksort(card A[], int p, int r){
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);

	}
}

int isStable(card A[], int n)
{
	int i;
	for (i = 0; i < n - 1; i++) {
		if (A[i].num == A[i + 1].num&&A[i].index > A[i + 1].index) return 0;
	}
	return 1;
}
