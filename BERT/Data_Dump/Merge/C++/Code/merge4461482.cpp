#include <bits/stdc++.h>
using namespace std;

#define MAX 2000000000

int n, S[500000];
int L[500000/2+1], R[500000/2+1];
int cnt;

void merge(int left, int mid, int right) {
	int n1 = mid - left, n2 = right - mid;
	for (int i = 0; i < n1; i++)
		L[i] = S[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = S[mid + i];
	L[n1] = MAX;
	R[n2] = MAX;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			S[k] = L[i];
			i++;
		} else {
			S[k] = R[j];
			j++;
		}
		cnt++;
	}
}

void mergesort(int left, int right) {
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergesort(left, mid);
		mergesort(mid, right);
		merge(left, mid, right);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> S[i];
	cnt = 0;
	mergesort(0, n);
	for (int i = 0; i < n - 1; i++)
		cout << S[i] << " ";
	cout << S[n - 1] << endl;
	cout << cnt << endl;
	return 0;
}

