#include "bits/stdc++.h"
using namespace std;

void print(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

int selectionSort(int A[], int N) {
	int count = 0;
	for (int i = 0; i < N; i++) {
		int minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj]) minj = j;
		}
		if (A[i] != A[minj]) {
			int temp = A[i];
			A[i] = A[minj];
			A[minj] = temp;
			count++;
		}
	}
	return count;
}

int main() {
	int N, A[100], count;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	count = selectionSort(A, N);
	print(A, N);
	cout << count << endl;
}
