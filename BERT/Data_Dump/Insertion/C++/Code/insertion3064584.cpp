#include <iostream>
#include <string>
#include <algorithm>

#include <stdio.h>
using namespace std;

void trace(int A[], int N) {
	for (int i = 0; i < N; i++) {
		cout << A[i];
		if (i != N - 1)
			cout << " ";
	}
	cout << endl;
}

void insertionSort(int A[], int N) {
	for (int i = 1; i < N; i++) {
		int tmp = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > tmp) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = tmp;
		trace(A, N);
	}
}

int main(void) {
	int N;
	int A[100];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	trace(A, N);
	insertionSort(A, N);
	return 0;
}

