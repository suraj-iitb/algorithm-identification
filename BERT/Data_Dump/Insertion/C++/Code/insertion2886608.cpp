#include "bits/stdc++.h"
using namespace std;

void print(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i!=0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

void insertionSort(int A[], int N) {
	int v, j;
	for (int i = 1; i < N; i++) {
		print(A, N);
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}
}


int main() {
	int N;
	cin >> N;
	int A[100];
	for (int i = 0; i < N; i++) cin >> A[i];

	insertionSort(A, N);
	print(A, N);
}
