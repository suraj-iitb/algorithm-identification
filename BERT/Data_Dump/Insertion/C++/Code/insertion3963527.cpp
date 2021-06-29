#include <stdio.h>

int main(void) {
	int N = 0;
	int a_A[1000];

	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a_A[i]);

	int v = 0, j = 0;
	for (int i = 1; i <= N; i++) {
		for (int k = 0; k < N; k++) {
			printf("%d", a_A[k]);
			if (k != N - 1) { printf(" "); }
			else { printf("\n"); }
		}
		if (i >= N) break;
		v = a_A[i];
		j = i - 1;
		while (j >= 0 && a_A[j] > v) {
			a_A[j + 1] = a_A[j];
			j--;
		}
		a_A[j + 1] = v;
	}
	return 0;
}
