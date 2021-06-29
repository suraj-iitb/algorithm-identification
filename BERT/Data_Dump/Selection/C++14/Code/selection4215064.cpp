#include "bits/stdc++.h"
using namespace std;
void InsertionSort(int N, vector<int>& A) {
	for (int i = 1; i < N; i++) {
		if (A.at(i - 1) > A.at(i)) {
			int tmp = A.at(i);
			int j = i - 1;
			while (j >= 0) {
				if (A.at(j) <= tmp) break;
				A.at(j + 1) = A.at(j);
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
long long GCD(long long A, long long B) {
	if (B == 0) return A;
	else return GCD(B, A % B);
}
bool Prime_Num(long long N) {
	for (long long i = 2; i <= sqrt(N); i++) {
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}
void BubbleSort(long long N, vector<long long>& A) {
	long long ans = 0;
	long long Limits = N;
	for (int i = 0; i < N; i++) {
		for (long long i = 1; i < Limits; i++) {
			if (A.at(i - 1) > A.at(i)) {
				ans++;
				swap(A.at(i - 1), A.at(i));
			}
		}
		Limits--;
	}
	for (long long i = 0; i < N; i++) {
		cout << A.at(i);
		if (i != N - 1) cout << ' ';
	}
	cout << endl << ans << endl;
}
void SelectionSort(long long N, vector<long long>& A) {
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		long long Pos = i;
		for (long long j = i; j < N; j++) {
			if (A.at(j) < A.at(Pos)) Pos = j;
		}
		if (Pos != i) {
			ans++;
			swap(A.at(i), A.at(Pos));
		}
	}
	for (long long i = 0; i < N; i++) {
		cout << A.at(i);
		if (i != N - 1) cout << ' ';
	}
	cout << endl << ans << endl;
}
int main() {
	long long N;
	cin >> N;
	vector<long long>A(N);
	for (long long i = 0; i < N; i++) {
		cin >> A.at(i);
	}
	SelectionSort(N, A);
}
