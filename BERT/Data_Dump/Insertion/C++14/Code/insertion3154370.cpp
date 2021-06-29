#include <bits/stdc++.h>
using namespace std;

void dump(const vector<int>& vec) {
	cout << vec[0];
	for (int i = 1; i < vec.size(); ++i)cout << " " << vec[i];
	cout << endl;
}

int main(void) {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	dump(A);
	for (int i = 1; i < N; ++i) {	
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
			--j;
		}
		A[j + 1] = v;
		dump(A);
	}
	return 0;
}
