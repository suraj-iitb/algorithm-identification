#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define INF 1000000001

using namespace std;

int n;

void counting_sort(vector<int>& A, vector<int>& B, int k) {
	vector<int> C(k,0);
	for (int i = 0; i < n; ++i) {
		++C[A[i]];
	}
	for (int i = 1; i < k; ++i) {
		C[i] += C[i-1];
	}
	for (int i = n-1; i >= 0; --i) {
		B[C[A[i]]-1] = A[i];
		--C[A[i]];
	}
	return;
}

int main(void) {
	int k = 0;
	cin >> n;
	vector<int> A(n),B(n);
	for (int i = 0; i < n; ++i) {
		cin >> A[i];
		k = max(A[i],k);
	}
	counting_sort(A,B,k+1);
	for (int i = 0; i < n; ++i) {
		cout << B[i];
		if (i < n-1) {
			cout << " ";
		}
	}
	cout << endl;
	return 0;
}

