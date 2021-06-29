#include <cstdio>

using namespace std;

const int MAX_N = 100;
int N;
int A[MAX_N];

void insertionSort(int *a, int n);

void show(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", *(a + i));
		if (i != n - 1) printf(" ");
	}
	printf("\n");
}

void solve() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	insertionSort(A, N);
}

int main() {
	solve();
}

void insertionSort(int *a, int n) {
	int v;

	show(a, N);

	for (int i = 1; i <= n - 1; i++) {
		v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
			a[j + 1] = v;
		}
		show(a, N);
	}
}
