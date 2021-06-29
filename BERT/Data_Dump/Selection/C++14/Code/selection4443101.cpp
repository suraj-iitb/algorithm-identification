#include <iostream>

#define N_MAX 100

using namespace std;

int selectionSort(int* A, const int N);

int main() {
	ios::sync_with_stdio(false);

	int N, A[N_MAX], swapCount;
	swapCount = 0;

	cin >> N;
	for(int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	swapCount = selectionSort(A, N);

	for(int i = 0; i < N; ++i) {
		cout << A[i] << (N - 1 == i ? "\n" : " ");
	}
	cout << swapCount << endl;
	return 0;
}

int selectionSort(int* A, const int N) {
	int swapCount = 0;
	int minj;
	for(int i = 0; i < N; ++i) {
		minj = i;
		for(int j = i; j < N; ++j) {
			if(A[j] < A[minj]) {
				minj = j;
			}
		}
		if(i != minj) {
			swap(A[i], A[minj]);
			swapCount++;
		}
	}
	return swapCount;
}
