#include <stdio.h>

#define Max 500000
#define INFTY 1000000000

struct card {
	char mark;
	int value;
}; typedef struct card card;

card L [Max/2 + 2], R[Max/2 + 2];

void  swap(card *x, card *y)
{
    card  buff;
	
	buff = *x;
	*x = *y;  
	*y = buff;
}

void printA(card A[Max], int N) {
	int i;

	for (i = 0; i < N; i++)
		printf("%c %d\n", A[i].mark, A[i].value);
}

void merge(card A[Max], int left, int mid, int right) {
	int i, j, k;

	int n1 = mid - left;
	int n2 = right - mid;

	// L[0...n1], R[0...n2] ?????????
	for (i = 0; i < n1; i++) L[i] = A[left + i];
	for (i = 0; i < n2; i++) R[i] = A[mid + i];

	L[n1].value = INFTY;
	R[n2].value = INFTY;
	i = 0;
	j = 0;

	for (k = left; k < right; k++) {
		if (L[i].value <= R[j].value)  A[k] = L[i++];
		else  A[k] = R[j++];
	}
}

void mergeSort(card A[Max], int left, int right) {
	int mid;

	if (left + 1 < right) {
		mid = (left + right)/2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int partition(card A[Max], int p, int r) {
	int x = A[r].value;
	int i = p-1;
	int j;
	
	for (j = p; j < r; j++)
		if (A[j].value <= x) swap(&A[++i], &A[j]);

	swap(&A[i + 1], &A[r]);

	return i + 1;
}

void quickSort(card A[Max], int p, int r) {
	int q;

	if (p < r) {
		q = partition(A, p, r);
		quickSort(A, p, q-1);
		quickSort(A, q+1, r);
	}
}

int main( ) {
	int N, i, q;
	card A[Max];
	card B[Max];

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf(" %c", &A[i].mark);
		scanf("%d", &A[i].value);
		B[i] = A[i];
	}

	mergeSort(A, 0, N);
	quickSort(B, 0, N - 1);

	for (i = 0; i < N; i++) {
		if (A[i].mark != B[i].mark) {
			printf("Not stable\n");
			break;
		}
		else if (i == N - 1) {
			printf("Stable\n");
		}
	}

	printA(B, N);

	return 0;
}
