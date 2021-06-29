#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int *A = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	int c = 0,temp;
	for (int i = 0; i < n -1; i++) {
		for (int j = n-1; j > i; j--) {
			if (A[j] < A[j-1]) {
				temp = A[j];
				A[j] = A[j-1];
				A[j-1] = temp;
				++c;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << A[i];
		if (i != n - 1)
			cout << ' ';
		else
			cout << endl;
	}
	cout << c << endl;
	delete[] A;
	return 0;
}
