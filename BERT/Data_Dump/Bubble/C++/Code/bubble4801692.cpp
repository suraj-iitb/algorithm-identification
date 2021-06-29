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

void BubbleSort(int n, int A[]) {
	bool flag = 1;
	while (flag) {
		flag = 0;
		for (int i = n - 1; i > 0; i--) {
			if (A[i] < A[i - 1]) {
				int temp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = temp;
				flag = 1;
				c++;
			}
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

	BubbleSort(n, A);

	delete[] A;

	return 0;
}
