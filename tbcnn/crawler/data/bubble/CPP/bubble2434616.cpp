#include <cstdio>

using namespace std;

static const int MAX_N = 100;
int A[MAX_N];
int N;

void show(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", *(a + i));
		if (i != n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

void bobleSort(int *a, int n);

void solve() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	bobleSort(A, N);
}

int main() {
	solve();
}

void bobleSort(int *a, int n) {
	bool f = true;
	int temp;
	int count = 0;

	while (f) {
		f = false;
		for (int j = n - 1; j != 0; j--) {
			if (A[j] < A[j - 1]) {
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				f = true;
				count++;		// ?????¢??°
			}
		}
	}
	show(a, N);
	printf("%d\n", count);
}
