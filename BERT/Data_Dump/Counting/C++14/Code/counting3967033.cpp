#include <iostream>

using namespace std;

int n;

void CountingSort(int A[], int B[], int k) {
	int C[10001] = {};
	for (int i = 0; i < n; ++i) C[A[i]]++;
	for (int i = 1; i <= k; ++i) C[i] += C[i - 1];
	for (int i = n - 1; i >= 0; --i) {
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
}

int A[2000000], B[2000001];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> A[i];
	CountingSort(A, B, 10000);
	for (int i = 1; i <= n; ++i) {
		if (i > 1) cout << " ";
		cout << B[i];
	}
	cout << endl;

	return 0;
}
