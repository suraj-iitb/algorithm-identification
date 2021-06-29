#include <iostream>

using namespace std;

void CountingSort(int A[], int B[], int n, int k) {
	int* C = new int[k];
	for (int i = 0; i < k; i++) {
		C[i] = 0;
	}
	for (int j = 0; j < n; j++) {
		C[A[j]]++;
	}
	for (int i = 1; i < k; i++) {
		C[i] = C[i] + C[i - 1];
	}
	for (int j = n - 1; j >= 0; j--) {
		B[C[A[j]] - 1] = A[j];
		C[A[j]]--;
	}
	delete[] C;
}

int main() {
	int n, k = 0;
	cin >> n;
	int* A = new int[n];
	int* B = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		if (k < A[i]) k = A[i];
		B[i] = 0;
	}

	CountingSort(A, B, n, k + 1);

	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << B[i];
	}
	cout << endl;
	delete[] A;
	delete[] B;
}
