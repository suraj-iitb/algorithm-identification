#include <cstdio>

using namespace std;

const int MAX_N = 100;
int A[MAX_N];
int N;

int selectionSort(int *a, int n);

void show(int *a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if (i != n - 1) {
			printf(" ");
		}
	}
	printf("\n");
}

void solve() {
	int num;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}

	num = selectionSort(A, N);
	show(A, N);
	printf("%d\n", num);
}

int main() {
	solve();
}

int selectionSort(int *a, int n) {
	int minj, temp;
	int num = 0;

	for (int i = 0; i < n; i++) {
		minj = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[minj]) {
				minj = j;
			}
		}
		if (minj != i) {
			temp = a[i];
			a[i] = a[minj];
			a[minj] = temp;
			num++;
		}
	}
	return num;
}
