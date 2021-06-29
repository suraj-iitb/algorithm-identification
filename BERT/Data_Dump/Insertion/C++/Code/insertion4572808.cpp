#include <iostream>

using namespace std;

static const int MAX = 100;

int main() {
	int A[MAX], n, v, j;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	for (int k = 0; k < n; k++) {
		if (k > 0)
			cout << " ";
		cout << A[k];
	}
	cout << endl;

	for (int i = 1; i < n; i++) {
		v = A[i];
		j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;

		for (int k = 0; k < n; k++) {
			if (k > 0)
				cout << " ";
			cout << A[k];
		}
		cout << endl;
	}
}
