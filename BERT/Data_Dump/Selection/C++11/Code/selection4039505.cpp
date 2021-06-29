//============================================================================
// Name        : alds_1_2_b_selectionSort.cpp
// Author      : lovesaemi
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int selectionSort(int A[], int N) {
	int i, j, t, sw = 0, minj;
	for (i = 0; i < N; i++) {
		minj = i;
		for (j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		t = A[i];
		A[i] = A[minj];
		A[minj] = t;
		if (i != minj) {
			sw++;
		}
	}
	return sw;
}

int main() {
	int A[100], N, sw;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sw = selectionSort(A, N);
	for (int i = 0; i < N; i++) {
		if (i) {
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}

