#include <bits/stdc++.h>
using namespace std;



int A[3000000], B[3000000], C[100000];

void CountingSort(int A[], int B[], int k, int n) {
	for (int i = 0; i <= k; i++)
		C[i] = 0;
	for (int i = 0; i < n; i++)
		C[A[i]]++;
	for (int i = 1; i <= k; i++)
		C[i] += C[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (k < A[i])
			k = A[i];
	}

	CountingSort(A, B, k, n);

	for (int i = 0; i < n; i++) {
		printf("%d", B[i]);
		if (i == n - 1)
			printf("\n");
		else
			printf(" ");
	}
}
