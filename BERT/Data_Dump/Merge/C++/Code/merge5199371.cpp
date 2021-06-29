#include <bits/stdc++.h>
using namespace std;

int cnt;

void merge(vector<int>& A, int l, int m, int r) {
  int n1 = m - l;
  int n2 = r - m;
  vector<int> L(n1), R(n2);
//L[0...n1], R[0...n2] を生成
  for (int i=0; i<n1; i++) L[i] = A[l+i]; L.push_back(1000000007);
  for (int i=0; i<n2; i++) R[i] = A[m+i]; R.push_back(1000000007);
  int i=0, j=0;
  for (int k=l; k<r; k++) {
  	if (cnt++, L[i] <= R[j]) {
  		A[k] = L[i]; i++;
  	} else {
  		A[k] = R[j]; j++;
  	}
  }
}

void mergeSort(vector<int>& A, int l, int r) {
	if (r-l>1) {
	    int m = (l+r)/2;
	    mergeSort(A, l, m);
	    mergeSort(A, m, r);
	    merge(A, l, m, r);
	}
    return;
}

int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i=0; i<n; i++) cin >> A[i];

	mergeSort(A, 0, n);

	for (int i=0; i<n; i++) {
		cout << A[i];
		if (i<n-1) cout << ' '; else cout << endl;
	}
  cout << cnt << endl;
	return 0;
}

