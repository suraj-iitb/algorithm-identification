#include <bits/stdc++.h>
using namespace std;

vector<int> countingSort(vector<int>& A, int k) {
	int N = A.size();
	vector<int> B(N), C(k+1, 0);
	for (int i=0; i<N; i++) C[A[i]]++;
	for (int i=1; i<=k; i++) C[i] += C[i-1];
	for (int i=N-1; i>=0; i--) B[--C[A[i]]] = A[i]; 
	return B;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
  for (int i=0; i<n; i++) cin >> A[i];

	vector<int> B = countingSort(A, 10000);

	for (int i=0; i<n; i++) {
		cout << B[i];
		if (i<n-1) cout << ' '; else cout << endl;
	}
	return 0;
}

