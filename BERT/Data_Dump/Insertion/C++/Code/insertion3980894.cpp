#include <iostream>
#include <algorithm>
#include <vector>
#include "stdio.h"

using namespace std;

void insertionSort(vector<int> &A, int N)
{
	for (int i = 1; i < N; i++) {
		int v = A[i];
		int j;
		for (j = i - 1; j >= 0 && A[j] > v; j--) {
			A[j + 1] = A[j];
		}
		A[j + 1] = v; 
		
		for (int k = 0; k < N; k++) {
			if (k > 0) cout << ' ';
			cout << A[k];
		}
		cout << '\n';
	}
}
	

int main(void)
{
	int N;
	cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int k = 0; k < N; k++) {
		if (k > 0) cout << ' ';
		cout << A[k];
	}
	cout << '\n';

	insertionSort(A, N);

	return 0;
}
