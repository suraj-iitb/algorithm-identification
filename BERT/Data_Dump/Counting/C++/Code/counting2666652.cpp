#include <cstdio>
#define V_MAX 10000+1
#define N_MAX 2000000+1

void countingSort(int n, int A[]) {
	int B[N_MAX], C[V_MAX] = {0};
	for (int i = 1; i <= n; i++) C[A[i]]++;
	for (int i = 1; i < V_MAX; i++) C[i] = C[i - 1] + C[i];
	for (int i = n; i > 0; i--) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
	for (int i = 1; i <= n; i++) A[i] = B[i];
}

int main() {
	int n, A[N_MAX];

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &A[i]);
	}

	countingSort(n, A);
	for (int i = 1; i <= n; i++) {
		if (i != n) printf("%d ", A[i]);
		else printf("%d\n", A[i]);
	}

	return 0;
}
