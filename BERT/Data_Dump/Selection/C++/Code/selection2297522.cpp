#include<iostream>
using namespace std;

int selectionSort(int A[], int N) {
	int n = 0;
	int minj;
	for (int i = 0; i < N; i++) {
		minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if ( i != minj ) n++;
		swap(A[i], A[minj]);
	}
	return n;
}

int main() {
	int A[100];
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];

	int n = selectionSort(A, N);
	
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}

	cout << endl;
	cout << n << endl;

	return	0;
}
