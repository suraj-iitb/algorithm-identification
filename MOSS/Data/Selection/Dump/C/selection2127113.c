#include<stdio.h>
int A[101] = {0};

void showA(int A[], int N) {
	int i;
	for (i = 0; i < N; ++i) {
		printf("%d ", A[i]);
	}
	printf("\n");
	return;
}

int SelectionSort(int A[], int N) {
	int i, j, tmp, minj;
	int cnt=0;
	
	for (i = 0; i < N; ++i) {
//		showA(A, N);
		minj = i;
		for (j = i; j < N; ++j) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;
			cnt++;
		}
	}
	return cnt;
}

int main(void) {
	int n, i, cnt;
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	cnt = SelectionSort(A, n);
	
	for (i = 0; i < n; ++i) {
		if (i != n - 1) {
			printf("%d ", A[i]);
		} else {
			printf("%d\n", A[i]);
		}
	}
	printf("%d\n", cnt);
	
	return 0;
}
