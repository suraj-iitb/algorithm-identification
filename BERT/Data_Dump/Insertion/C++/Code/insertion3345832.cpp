#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int v = 0, j = 0;

void insertionSort(int A[], int N);

int main() {
	int N;

	int A[1001];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];	
	}
	
	insertionSort(A, N);

	cout << A[0];
	for (int k = 1; k < N; k++) {
		cout << " " << A[k];
	}
	cout << endl;
}
		
void insertionSort(int A[], int N) {
	for (int i = 1; i < N; i++) {
		cout << A[0];
		for (int k = 1; k < N; k++) {
			cout << " " << A[k];
		}
		cout << endl;

		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}
}
