#include <stdio.h>
#include <stdlib.h>

typedef struct CardStruct {
	char suit;
	int value;
}Card;

int SENTINEL = 1000000;
Card L[500000 / 2 + 2];
Card R[500000 / 2 + 2];


int partition(Card A[], int p, int r) {
	int x = A[r].value;
	int i = p - 1;
	for (int j = p; j < r; j++) {
		if (A[j].value <= x) {
			i++;
			// swap A[i] and A[j]
			Card tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	// swap A[i+1] and A[r]
	Card tmp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = tmp;
	return i + 1;
}

void quicksort(Card A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

void bubblesort(Card A[], int n) {
	int flag = 1;
	while (flag) {
		flag = 0;
		for (int j = n - 1;j > 0;j--) {
			if (A[j].value < A[j - 1].value) {
				// swap A[i] and A[j]
				Card tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				flag = 1;
			}
		}
	}
}

void merge(Card A[], int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	//	int* L = (int*)malloc(sizeof(int) * (n1+1));
	//	int* R = (int*)malloc(sizeof(int) * (n2 + 1));
	int i, j, k;

	for (i = 0; i < n1;i++) {
		L[i] = A[left + i];
	}
	for (i = 0; i < n2;i++) {
		R[i] = A[mid + i];
	}
	L[n1].value = SENTINEL;
	R[n2].value = SENTINEL;
	i = 0, j = 0;
	for (k = left;k < right; k++) {
		if (L[i].value <= R[j].value) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
	}
	//	free(L);
	//	free(R);
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


int main() {
	int n = 0;
	Card* A;
	Card* B;
	char str[10];

	scanf("%d",&n);
	A = (Card*)malloc(n * sizeof(Card));
	B = (Card*)malloc(n * sizeof(Card));
	for (int i = 0;i < n; ++i) {
		scanf("%s %d", str, &A[i].value);
		A[i].suit = str[0];
	}
	for (int i = 0;i < n; ++i) {
		B[i] = A[i];
	}

	quicksort(A, 0, n-1);
//	bubblesort(B, n);
	mergeSort(B, 0, n);

	int flag = 1;
	for (int i = 0;i < n; ++i) {
		if (!((A[i].suit == B[i].suit) && (A[i].value == B[i].value))) {
			flag = 0;
			break;
		}
	}
	if (flag) {
		printf("Stable\n");
	}
	else {
		printf("Not stable\n");
	}

	for (int i = 0;i < n; ++i) {
		printf("%c %d\n", A[i].suit, A[i].value);
	}

	free(A);
	return 0;
}
