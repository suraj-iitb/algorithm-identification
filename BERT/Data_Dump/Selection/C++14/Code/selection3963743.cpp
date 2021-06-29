#include <iostream>

using namespace std;

int selectionSort(int A[], int N) {
	int res = 0;
	for (int i = 0; i < N; ++i) {
		int minj = i;
		for (int j = i; j < N; ++j)
			if (A[j] < A[minj]) minj = j;
		if (i != minj) swap(A[i], A[minj]), res++;
	}
	return res;
}

int main() {
	int A[100];
	int N; cin >> N;
	for (int i = 0; i < N; ++i) cin >> A[i];
	int ans = selectionSort(A, N);
	for (int i = 0; i < N; ++i) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl << ans << endl;

	return 0;
}
