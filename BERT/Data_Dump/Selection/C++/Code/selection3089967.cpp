#include <iostream>
#include <string>
//#include <algorithm>

#include <stdio.h>
using namespace std;

void swap(int &a, int &b) {
    int tmp = b;
    b = a;
    a = tmp;
}

int selectionSort(int A[], int N) {
    int sw = 0;
    int i = 0;
	for (int i = 0; i < N - 1; i++) {
		int minj = i;
		for (int j = i + 1; j < N; j++) {
			if (A[j] < A[minj])
				minj = j;
		}
		if (minj != i) {
			swap(A[i], A[minj]);
			sw++;
		}
	}
    return sw;
}

int main(void) {
	int N;
    int sw;
	int A[100];
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
    sw = selectionSort(A, N);


	for (int i = 0; i < N; i++) {
		if (i != 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}

