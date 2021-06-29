#include <iostream>

using namespace std;

int n;

void CountingSort(int A[], int B[], int k) {
	int C[k + 1] = { 0 };

	for (int i = 0; i < n; i++) {
		C[A[i]]++;
	}

	for (int i = 1; i <= k; i++) {
		C[i] += C[i - 1];
	}

	for (int i = 0; i < n; i++) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}

int main() {
	cin >> n;

	int A[n], B[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	CountingSort(A, B, 10000);

	for (int i = 0; i < n - 1; i++) {
		cout << B[i] << " ";
	}
	cout << B[n - 1] << endl;

	return 0;
}
