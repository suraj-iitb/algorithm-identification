#include <algorithm>
#include <iostream>
using namespace std;

void trace(int A[], int n) {
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
}

int main() {
	int n; cin >> n;
	int A[110];

	for (int i = 0; i < n; i++) cin >> A[i];

	trace(A, n);
	for (int i = 1; i < n; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
		trace(A, n);
	}

	return 0;
}
