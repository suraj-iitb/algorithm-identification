#include <iostream>
using namespace std;

int cnt = 0;

void SelectionSort(int *A, int N) {
	for (int i = 0; i <= N - 1; ++i) {
		int minj = i;
		for (int j = i; j <= N - 1; ++j) {
			if (A[j] < A[minj]) minj = j;
		}
		if (A[i] != A[minj]) {
			int tmp;
			tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;
			cnt++;
		}
	}
}

int main() {
	int N; cin >> N;
	int A[110];

	for (int i = 0; i < N; ++i) cin >> A[i];

	SelectionSort(A, N);

	for (int i = 0; i < N; ++i) {
		cout << A[i];
		if (i != N - 1) cout << " ";
	}
	cout << endl << cnt << endl;
}
