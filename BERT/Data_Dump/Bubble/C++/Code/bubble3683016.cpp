#include <stdio.h>
#include <stdbool.h>

int A[110];
int cnt = 0;

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubbleSort(int *A, int N) {
	bool flag = true;
	while (flag) {
		flag = false;
		for (int j = N - 1; j >= 1; --j) {
			if (A[j] < A[j - 1]) {
				int tmp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = tmp;
				flag = 1;
				cnt++;
			}
		}
	}
}

int main(void){
	int n;
	scanf("%i", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%i", &A[i]);
	}
	bubbleSort(A, n);
	for (int i = 0; i < n; ++i) {
		if (i != n - 1) printf("%i ", A[i]);
		else printf("%i\n", A[i]);
	}
	printf("%i\n", cnt);
}

