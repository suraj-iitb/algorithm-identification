#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> pci;

int partition(vector<pci>& A, int p, int r) {
	int x = A[r-1].second;
	int i = p-1;
	for (int j=p; j<r-1; j++) {
		if (A[j].second <= x) swap(A[++i], A[j]);
	}
	swap(A[++i], A[r-1]);
	return i;
}

void quickSort(vector<pci>& A, int p, int r) {
	if (r-p>1) {
		int q = partition(A, p, r);
		quickSort(A, p, q);
		quickSort(A, q+1, r);
	}
}

void merge(vector<pci>& A, int l, int m, int r) {
  int n1 = m - l;
  int n2 = r - m;
  pci inf = pci('X', 1000000007);
  vector<pci> L(n1), R(n2);
  for (int i=0; i<n1; i++) L[i] = A[l+i]; L.push_back(inf);
  for (int i=0; i<n2; i++) R[i] = A[m+i]; R.push_back(inf);
  int i=0, j=0;
  for (int k=l; k<r; k++) {
  	if (L[i].second <= R[j].second) {
  		A[k] = L[i]; i++;
  	} else {
  		A[k] = R[j]; j++;
  	}
  }
}

void mergeSort(vector<pci>& A, int l, int r) {
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
	vector<pci> A(n), B;
	for (int i=0; i<n; i++) cin >> A[i].first >> A[i].second;
  B = A;

	quickSort(A, 0, n);
  mergeSort(B, 0, n);
  
  bool flag = true;
  for (int i=0; i<n; i++) flag &= (A[i] == B[i]);
  cout << (flag ? "Stable" : "Not stable") << endl;
	for (int i=0; i<n; i++) {
		cout << A[i].first << ' ' << A[i].second << endl;
	}
	return 0;
}

