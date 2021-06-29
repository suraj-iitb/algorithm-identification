#include<stdio.h>
#define MAX 100000

typedef struct {
	char suit;
	int value;
} Card;

void swap(Card *A, Card *B) {
	Card temp;

	temp = *A;
	*A = *B;
	*B = temp;
}

Card L[MAX / 2 + 2], R[MAX / 2 + 2];

void merge(Card A[], int left, int mid, int right) {
	int i, j, k;
	int n1, n2;

	n1 = mid - left;
	n2 = right - mid;
	for (i = 0; i < n1; i++) {
		L[i] = A[left + i];
	}
	for (i = 0; i < n2; i++) {
		R[i] = A[mid + i];
	}
	L[n1].value = R[n2].value = 20000000;
	i = j = 0;
	for (k = left; k < right; k++) {
		if (L[i].value <= R[j].value) {
			A[k] = L[i++];
		}
		else {
			A[k] = R[j++];
		}
	}

}

void mergeSort(Card A[], int left, int right) {
	int mid;
	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

//Quick Sort
int partiton(Card A[], int p, int r) {
	int i, j;
	Card x;

	x = A[r];
	i = p - 1;
	for (j = p; j < r; j++) {
		if (A[j].value <= x.value) {
			i++;
			swap(&A[i], &A[j]);
		}
	}
	swap(&A[i + 1], &A[r]);
	return i + 1;
}

void quickSort(Card A[], int p, int r) {
	int q;

	if (p < r) {
		q = partiton(A, p, r);
		quickSort(A, p, q - 1);
		quickSort(A, q + 1, r);
	}
}

//Sort方法の比較
int isStable(Card C1[], Card C2[], int n) {
	int i;

	for (i = 0; i < n; i++) {
		if (C1[i].suit != C2[i].suit) {
			return 0;
		}
	}
	return 1;
}

int main() {
	Card Cm[MAX], Cq[MAX];
	int n, i, v;
	char S[10];

	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s", S);
		scanf("%d", &v);

		Cm[i].suit = Cq[i].suit = S[0];
		Cm[i].value = Cq[i].value = v;
	}

	mergeSort(Cm, 0, n);
	quickSort(Cq, 0, n - 1);

	if (isStable(Cm, Cq, n)) {
		printf("Stable\n");
	}
	else {
		printf("Not stable\n");
	}
	for (i = 0; i < n; i++) {
		printf("%c %d\n", Cq[i].suit, Cq[i].value);
	}

	return 0;
}
