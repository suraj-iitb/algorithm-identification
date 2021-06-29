#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N; cin >> N;

	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int j = 0; j < N; j++) {
		if (j != N - 1) cout << A[j] << " ";
		else cout << A[j] << endl;
	}

	for (int i = 1; i< N; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			j--;
			A[j + 1] = v;
		}
		for (int j = 0; j < N; j++) {
			if (j != N - 1) cout << A[j] <<" ";
			else cout << A[j] << endl;
		}
	}

}
