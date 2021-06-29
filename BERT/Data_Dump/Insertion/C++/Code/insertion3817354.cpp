#include <iostream>
#include <algorithm>
using namespace std;

static const int MAX = 100;

int main() {
	int A[MAX], n;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {
		if (i == n - 1) {
			cout << A[i] << endl;
		}
		else {
			cout << A[i] << ' ';
		}

	}


	for (int i = 1; i < n; i++) {
		int v = A[i];
		int j = i - 1;

		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		for (int i = 0; i < n; i++) {
			if (i == n - 1) {
				cout << A[i] << endl;
			}
			else {
				cout << A[i] << ' ';
			}

		}
	}
}
