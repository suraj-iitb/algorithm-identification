#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, *A;
	cin >> N;
	A = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N; j++) {
			if (j != 0) {
				cout << " ";
			}
			cout << A[j];
		}
		cout << "\n";
		if (i == N) break;

		int v = A[i];
		int j = i - 1;

		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = v;
	}
}

