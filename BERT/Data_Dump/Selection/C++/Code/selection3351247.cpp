#include <iostream>
#include <string>

using namespace std;

int selectionSort(int A[], int N);

int main() {
	int N;
	int count = 0;
	cin >> N;

	int A[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];	
	}

	count = selectionSort(A, N);

	for (int i = 0; i < N; i++) {
		if (i < N - 1)
			cout << A[i] << " ";
		else
			cout << A[i] << endl;
	}
	cout << count << endl;
}

int selectionSort(int A[], int N) {
	int count = 0;
	int minj = 0;

	for (int i = 0; i < N; i++) {
		minj = i;
		for (int j = i; j < N; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		if (i != minj) {
			swap(A[i], A[minj]);
			count++;
		}
	}

	return count;
}
