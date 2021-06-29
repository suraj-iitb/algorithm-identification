#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <deque>
#define ll long long

using namespace std;

vector<int>A;
int k;


vector<int> CountingSort() {
	vector<int>C(k + 1, 0);
	for (int i = 0; i < A.size(); i++) {
		C[A[i]]++;
	}
	for (int i = 1; i <= k; i++) {
		C[i] = C[i - 1] + C[i];
	}
	vector<int>B(A.size());
	for (int i = A.size() - 1; i >= 0; i--) {
		B[C[A[i]] - 1] = A[i];
		C[A[i]]--;
	}
	return B;
}

int main() {
	int N; cin >> N;
	A.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		k = max(k, A[i]);
	}

	vector<int> B = CountingSort();
	for (int i = 0; i < B.size(); i++) {
		if (i != 0) cout << " ";
		cout << B[i];
	}
	cout << endl;



	return 0;
}



