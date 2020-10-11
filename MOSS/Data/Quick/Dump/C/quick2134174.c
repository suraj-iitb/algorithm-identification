#include <stdio.h>
#include <limits.h>

typedef struct {
	char mark;
	int number;
} card;

card L[50002] = {0};
card R[50002] = {0};

void showM(card A[], int n) {
	int i;
	for(i = 0; i < n; ++i) {
		printf("%c %d\n", A[i].mark, A[i].number);
	}
	return;
}

int partition(card A[], int p, int r) {
	int x, i, j;
	card tmp;
	x = A[r].number;
	i = p - 1;

	for (j = p; j < r; ++j) {
		if (A[j].number <= x) {
			++i;
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}
	tmp = A[i+1];
	A[i+1] = A[r];
	A[r] = tmp;
	return i + 1;
}

void quicksort(card A[], int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

void Merge(card A[], int left, int mid, int right) {
	int n1, n2;
	int i, j, k;
	n1 = mid - left;
	n2 = right - mid;
//	printf("A\n");
//	showM(A,right);
	for (i = 0; i < n1; ++i) {
		L[i] = A[left + i];
	}
	for (i = 0; i < n2; ++i) {
		R[i] = A[mid + i];
	}
	/* printf("L\n"); */
	/* showM(L, n1); */
	/* printf("R\n"); */
	/* showM(R, n2); */
	L[n1].number = INT_MAX;
	R[n2].number = INT_MAX;
	i = 0;
	j = 0;
	
	for (k = left; k < right; ++k) {
		if (L[i].number <= R[j].number) {
			A[k] = L[i];
			++i;
		} else {
			A[k] = R[j];
			++j;
		}
	}
	return;
}

void MergeSort(card A[], int left, int right) {
	int mid;
//	showM(A, right);
	if (left + 1 < right) {
		mid = (left + right) / 2;
		MergeSort(A, left, mid);
		MergeSort(A, mid, right);
		Merge(A, left, mid, right);
	}
	return;
}

int main(void) {
	int i, n;
	int flag = 0;
	card A[100000] = {0};
	card B[100000] = {0};
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf(" %c %d", &A[i].mark, &A[i].number);
		B[i] = A[i];
	}

	
	quicksort(A, 0, n-1);
	MergeSort(B, 0, n);
	
	for (i = 0; i < n; ++i) {
		if (A[i].mark != B[i].mark) {
			flag = 1;
			break;
		}
	}
	if (flag) {
		printf("Not stable\n");
	} else {
		printf("Stable\n");
	}
	
	for (i = 0; i < n; ++i) {
		printf("%c %d\n", A[i].mark, A[i].number);
	}
	return 0;
}
