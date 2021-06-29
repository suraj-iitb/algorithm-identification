#include <iostream>
#include <algorithm>
using namespace std;

const int LEN = 20000000;
const int MAX = 10000;
int A[LEN], B[LEN], C[MAX+1];

void CountingSort(int n, int A[], int B[], int k) {
	for (int i = 0; i <= k; i++)
		C[i] = 0;
	for (int i = 0; i < n; i++)
		C[A[i]]++;
	for (int i = 1; i <= k; i++)
		C[i] += C[i-1];
	for (int i = n-1; i >= 0; i--) {
		B[C[A[i]]-1] = A[i];
		C[A[i]]--;
	}
}

int main() {
	int n, k = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
		k = max(k, A[i]);
		B[i] = 0;
	}
	CountingSort(n, A, B, k);
	
	cout << B[0];
	for (int i = 1; i < n; i++) cout << ' ' << B[i];
	cout << endl;
}

