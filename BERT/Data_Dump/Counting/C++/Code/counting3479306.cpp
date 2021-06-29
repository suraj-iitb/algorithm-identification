#include <bits/stdc++.h>
using namespace std;
#define MAX 2000000
#define K 10000

int A[MAX], B[MAX];

void countingSorting(int *A, int *B, int k, int len)
{
	int C[k];
	int i, j;
	for (i = 0; i < k; i++) {
		C[i] = 0;
	}
	for (i = 0; i < len; i++) {
		C[A[i]] = C[A[i]] + 1;
	}
	for (i = 1; i < k; i++) {
		C[i] = C[i] + C[i - 1];
	}
	for (i = 0; i < len; i++) {
		C[A[i]] = C[A[i]] - 1;
		B[C[A[i]]] = A[i];
	}
}

int main(void) {
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> A[i];
	countingSorting(A, B, K, n);

	for (i = 0; i < n; i++) 
	{
		if (i) cout << " ";
		cout << B[i];
	}
	cout << endl;
}
