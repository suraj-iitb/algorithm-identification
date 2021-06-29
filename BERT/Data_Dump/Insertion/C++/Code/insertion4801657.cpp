#include <iostream>
using namespace std;

void print(int n, int A[]) {
	cout << A[0];
	for (int i = 1; i < n; i++) {
		cout << " " << A[i];
	}
	cout << endl;
}

void InsertionSort(int n, int A[]) {
	for (int i = 0; i < n; i++) {
		int v = A[i];
		int j = i - 1;
		while (0 <= j && v < A[j]) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		print(n, A);
	}
}

int main() {
	int n;
	cin >> n;
	int* A = new int[n] ;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	InsertionSort(n, A);

	delete[] A;

	return 0;
}
