#include <bits/stdc++.h>
using namespace std;

int selectionSort(int A[], int N) {
	int result = 0;
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj]) minj = j;
		}
		swap(A[i], A[minj]);
		result += int(minj != i);
	}
	return result;
}

int main() {
	int N, *A;
	cin >> N;
	A = new int[N];
	for (int i = 0; i < N; i++) cin >> A[i];

	int cnt = selectionSort(A, N);

	for (int i = 0; i < N; i++) {
		if (i != 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << cnt << endl;
}

