#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
using namespace std;

int selectionSort(int A[], int N) {
	int i, j, minj,sw;
	sw = 0;
	for (int i = 0; i<N-1; i++) {
		minj = i;
		for (int j = i + 1; j < N; j++) {
			if (A[minj] > A[j]) {
				minj = j;
			}
		}
		if (minj != i) {
			swap(A[minj], A[i]);
			sw++;
		}
		}
	return sw;
	}

int main() {
	int N, A[100],sw;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sw = selectionSort(A,N);

	for (int i = 0; i < N; i++) {
		if (i) {
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;
}
