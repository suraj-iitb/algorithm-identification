#include <iostream>
using namespace std;

int A[1000];
int N;

void Show(int A[], int N) {
	for (int i = 0; i < N; ++i) {
		if (i) {
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
}

void insertionSort(int A[], int N, int i, int j) {
	int v = A[i];
	while (j >= 0  && A[j] > v) {
		A[j + 1] = A[j];
		--j;
	}
		A[j + 1] = v;
	
}


int main() {
	int j;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}

	Show(A, N);
	for (int i = 1; i < N; ++i) {
		j = i - 1;
		insertionSort(A, N, i, j);
		Show(A, N);
	}

}
