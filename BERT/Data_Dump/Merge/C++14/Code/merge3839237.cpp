#include<bits/stdc++.h>
using namespace std;

int L[260000];
int A[510000];
int R[260000];
long long c = 0;

void merge(int l, int m, int r) {
	int n1 = m - l;
	int n2 = r - m;
	for (int i = 0; i < n1; i++) {
		L[i] = A[l + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = A[i + m];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
		
	int i = 0, j = 0;

	for (int k = l; k < r; k++) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		c++;
	}
}

void mergeSort(int l,int r) {
	if (l + 1 < r) {
		int m = (l + r) / 2;
		mergeSort(l, m);
		mergeSort(m, r);
		merge(l, m, r);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	mergeSort(0, N);
	for (int i = 0; i < N; i++) {
		if (i) cout << " ";
		cout << A[i];
	}
	cout << endl;
	cout << c << endl;
}
