#include<iostream>
using namespace std;

static const int MAX = 100;

int main() {
	int n;
	int A[MAX];
	int num = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n - 1; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (A[j] < A[minj]) {
				minj = j;
			}
		}
		int tmp = A[i];
		A[i] = A[minj];
		A[minj] = tmp;
		if (i != minj) { num++; }
	}

	for (int i = 0; i < n; i++) {
		cout << A[i];
		if (i < n - 1) {
			cout << ' ';
		}
	}
	cout << endl;
	cout << num << endl;
	return 0;
}
