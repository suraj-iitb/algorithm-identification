#include <iostream>
#include <string>
using namespace std;
void insertionSort(int A[], int N) {
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < N - 1; j++) {
			cout << A[j] << ' ';
		}
		cout << A[N - 1] << endl;
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}
	for (int i = 0; i < N - 1; i++) {
		cout << A[i] << ' ';
	}
	cout << A[N - 1] << endl;
}

int main(void) {
	int N, A[200];
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	insertionSort(A, N);
	return 0;
}
