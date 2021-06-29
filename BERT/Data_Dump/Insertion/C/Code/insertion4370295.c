#include <stdio.h>

void print_array(const int* array, int num) {
	int i;
	for (i = 0; i < num; i++) {
		printf(" %d" + !i, array[i]);
	}
	putchar('\n');
}

int main(void) {
	int N;
	int A[128];
	int i, j;
	if (scanf("%d", &N) != 1) return 1;
	for (i = 0; i < N; i++) {
		if (scanf("%d", &A[i]) != 1) return 1;
	}
	print_array(A, N);
	for (i = 1; i < N; i++) {
		int v = A[i];
		for (j = i - 1; j >= 0 && A[j] > v; j--) A[j + 1] = A[j];
		A[j + 1] = v;
		print_array(A, N);
	}
	return 0;
}


