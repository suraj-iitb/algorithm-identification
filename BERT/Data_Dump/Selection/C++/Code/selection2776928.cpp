#include <iostream>
using namespace std;

int A[100];

int selectionSort(int A[], int n) {
	int c = 0, minj;

	for (int i = 0; i < n - 1; ++i) {
		minj = i;
		for (int j = i; j < n; ++j) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
			if (i != minj) {
				int t = A[minj];
				A[minj] = A[i];
				A[i] = t;
				++c;
			}
		
	}
	return c;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
	}
	int c = selectionSort(A, n);
	for (int i = 0; i < n; ++i) {
		if (i) {
			cout << " ";
		}
		cout << A[i];
	}
	cout << endl;
	cout << c << endl;
}
