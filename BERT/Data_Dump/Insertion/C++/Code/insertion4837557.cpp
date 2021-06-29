#include<iostream>

using namespace std;

static const int MAX = 100;

void show(int* A, int n) {
	for (int i = 0; i < n; i++) {
		cout << A[i];
		if (i < n - 1) {
			cout << ' ';
		}
	}
	cout << endl;
	return;
}

int main()
{
	int n;
	int A[MAX];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	show(A, n);
	for (int i = 1; i < n; i++) {
		int v = A[i];
		int j = i - 1;

		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		show(A, n);
	}

	return 0;
}
