#include <bits/stdc++.h>
using namespace std;
void InsertionSort(long long N, vector<long long>&A) {
	for (long long i = 0; i < N; i++) {
		cout << A.at(i);
		if (i != N - 1) cout << ' ';
	}
	cout << endl;
	for (long long i = 1; i < N; i++) {
		long long v = A.at(i);
		long long j = i - 1;
		while (j >= 0 && A.at(j) > v) {
			A.at(j + 1) = A.at(j);
			j--;
		}
		A.at(j + 1) = v;
		for (long long k = 0; k < N; k++) {
			cout << A.at(k);
			if (k != N - 1) cout << ' ';
		}
		cout << endl;
	}
}
int main() {
	long long N; cin >> N;
	vector<long long>A(N);
	for (long long i = 0; i < N; i++) {
		cin >> A.at(i);
	}
	InsertionSort(N, A);
}
