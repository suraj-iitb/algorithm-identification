#include<iostream>

using namespace std;

int main() {

	int N = 0;
	int A[100] = {};

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> A[i];

	}

	for (int u = 0; u < N; u++) {

		cout << A[u];

		if (u != N - 1) cout << " ";

	}

	cout << endl;

	for (int i = 1; i < N; i++) {

		int v = A[i];

		int u;

		for (u = i - 1; u >= 0; u--) {

			if (v > A[u]) break;

			A[u + 1] = A[u];

		}

		A[u + 1] = v;

		for (int u = 0; u < N; u++) {

			cout << A[u];

			if (u != N - 1) cout << " ";

		}

		cout << endl;

	}
	
	return 0;

}
