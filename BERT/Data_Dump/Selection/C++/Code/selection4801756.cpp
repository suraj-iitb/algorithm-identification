#include <iostream>
using namespace std;
int c = 0; //交換回数

void print(int n, int A[]) {
	cout << A[0];
	for (int i = 1; i < n; i++) {
		cout << " " << A[i];
	}
	cout << endl;
	cout << c << endl;
}

void SelectionSort(int n, int A[]) {
	bool flag = 0;
	for (int i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (A[minj] > A[j]) {
				minj = j;
				flag = 1;
			}
		}
		if (flag == 1) {
			swap(A[i], A[minj]);
			c++;
			flag = 0;
		}
	}
	print(n, A);
}

int main() {
	int n;
	cin >> n;
	int* A = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	SelectionSort(n, A);

	delete[] A;

	return 0;
}
