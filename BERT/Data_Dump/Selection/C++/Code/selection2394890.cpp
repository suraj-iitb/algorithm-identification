#include<iostream>
using namespace std;

int selectionSort(int A[], int N) {
	int minj, sw=0;
	for (int i = 0; i <= N-1; i++) {
		minj = i;
		for (int j = i; j <= N - 1; j++) {
			if (A[j] < A[minj]) minj = j;
		}
		if (i != minj) {
			swap(A[i], A[minj]);
			sw++;
		}
	}
	return sw;
}

int main(void) {
	int N, A[100], sw;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sw = selectionSort(A, N);

	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;

	cout << sw << endl;

	return 0;
}
