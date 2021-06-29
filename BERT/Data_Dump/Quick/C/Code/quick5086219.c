#include <stdio.h>
#include <stdlib.h>
#define INFTY 2000000000
typedef struct card {
	char suit;
	int value;
}card;
card* B;
card* L, * R;
void merge(int, int, int);
void mergeSort(int, int);

void quicksort(card*, int, int);
int partition(card*, int, int);
void swap(card*, card*);
int Stablecheck(card*, card*, int);

int main() {
	card* A;
	int n, p = 0;
	int i,judge;

	scanf("%d", &n);
	A = (card*)malloc(sizeof(card) * n);
	B = (card*)malloc(sizeof(card) * n);
	for (i = 0; i < n; i++) {
		scanf(" %c %d", &A[i].suit, &A[i].value);
		B[i] = A[i];
	}

	quicksort(A, p, n - 1);
	mergeSort(0, n);
	judge = Stablecheck(B, A, n);
	if (judge == 1)printf("Stable\n");
	else printf("Not stable\n");

	for (i = 0; i < n; i++) {
		printf("%c %d\n", A[i].suit, A[i].value);
	}

	return 0;
}

int partition(card* A, int p, int r) {
	int i, j, x;
	x = A[r].value;
	i = p - 1;
	for (j = p; j <= r - 1; j++) {
		if (A[j].value <= x) {
			i += 1;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[r]);

	return i + 1;
}
void swap(card* x, card* y) {
	card temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void quicksort(card* A, int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

int Stablecheck(card* Cin, card* Cout, int N) {
	int i;
	for (i = 0; i < N; i++) {
		if (Cin[i].suit != Cout[i].suit)return 0;
	}
	return 1;
}

void merge(int left, int mid, int right) {
	int n1, n2;
	int i, j, k;
	n1 = mid - left;
	n2 = right - mid;
	L = (card*)malloc(sizeof(card) * (n1 + 1));
	R = (card*)malloc(sizeof(card) * (n2 + 1));
	for (i = 0; i <= n1 - 1; i++)
		L[i] = B[left + i];
	for (i = 0; i <= n2 - 1; i++)
		R[i] = B[mid + i];
	L[n1].value = INFTY;
	R[n2].value = INFTY;
	i = 0;
	j = 0;
	for (k = left; k <= right - 1; k++) {
		if (L[i].value <= R[j].value) {
			B[k] = L[i];
			i = i + 1;
		}
		else {
			B[k] = R[j];
			j = j + 1;
		}
	}
	free(R);
	free(L);
}

void mergeSort(int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
}

