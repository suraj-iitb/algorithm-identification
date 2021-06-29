#include "bits/stdc++.h"
using namespace std;
void InsertionSort(int N, vector<int>& A) {
	for (int i = 1; i < N; i++) {
		if (A.at(i - 1) > A.at(i)) {
			int tmp = A.at(i);
			int j = i;
			while (j > 0) {
				if (A.at(j - 1) <= tmp) break;
				A.at(j) = A.at(j - 1);
				j--;
			}
			A.at(j) = tmp;
		}
		for (int k = 0; k < N; k++) {
			cout << A.at(k);
			if (k != N - 1) cout << ' ';
		}
		cout << endl;
	}
}
int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A.at(i);
		cout << A.at(i);
		if (i != N - 1) cout << ' ';
	}
	cout << endl;
	InsertionSort(N, A);
}
