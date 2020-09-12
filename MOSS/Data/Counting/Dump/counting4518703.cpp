#include<iostream>
using namespace std;

static const int MAX = 2000000;

int n;
int C[MAX];

void CountingSort(int A[], int B[], int k) {
	for (int i = 0; i <= k; i++) {
		C[i] = 0;
	}

	for (int j = 1; j < n + 1; j++) {
		C[A[j]] += 1;
	}

	for (int i = 1; i <= k; i++) {
		C[i] = C[i - 1] + C[i];
	}
	
	for (int j = n; j > 0; j--) {
		B[C[A[j]]] = A[j];
		C[A[j]]--;

	}
}

int main() {
	cin >> n;
	int A[MAX+1], B[MAX+1];
	int k = 0;
	for (int i = 1; i < n+1; i++) {
		cin >> A[i];
		if (A[i] > k) {
			k = A[i];
		}
	}
	CountingSort(A, B, k);

	for (int i = 1; i <= n; i++) {
		if (i > 1) {
			cout << " ";
		}
		cout << B[i];
	}
	cout << endl;

}
