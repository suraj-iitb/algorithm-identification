#include <iostream>

using namespace std;

void trace(int A[], int N) {
	for (int i = 0; i < N; i++) {
		if (i > 0) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

int selectionSort(int A[], int N) {
	int minj;
	int tmp;
	int count = 0;

	for (int i = 0; i < N; i++) {
		minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;	
			}
		}
		
		if (minj != i) {
			tmp = A[i];
			A[i] = A[minj];
			A[minj] = tmp;

			count++;
		}
	}

	trace(A, N);

	return count;
}

int main() {
	int N;
	int A[100];
	int count;
	
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	
	count = selectionSort(A, N);			

	cout << count << endl;

	return 0;
}
