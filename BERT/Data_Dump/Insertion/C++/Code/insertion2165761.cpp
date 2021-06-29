#include <cstdio>
#include <iostream>

using namespace std;

void print(int A[], int N) {
	for (int i = 0; i < N; ++i) {
		if (i != 0)
			cout << " " << A[i];
		else
			cout << A[i];
	}
	cout << endl;
}

void insertionSort(int A[], int N) {
	print(A, N);
	for (int i = 1; i < N; ++i) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			--j;
		}
		A[j + 1] = v;
		print(A, N);
	}
}

int main() {

	int n;
	scanf("%d", &n);

	int A[n];
	for (int i = 0; i < n; ++i) {
		int v;
		scanf("%d", &v);
		A[i] = v;
	}

	insertionSort(A, n);

	return 0;
}
