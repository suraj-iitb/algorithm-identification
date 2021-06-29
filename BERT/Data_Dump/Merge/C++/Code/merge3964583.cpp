#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define Max 500000
#define Sentinel 1e9;

int l[Max / 2 +2], r[Max / 2 + 2];
int cnt;

void merge(int a[], int n, int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	rep(i, n1) l[i] = a[left + i];
	rep(i, n2) r[i] = a[mid + i];
	l[n1] = r[n2] = Sentinel;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		cnt++;
		if (l[i] <= r[j]) {
			a[k] = l[i++];
		} else {
			a[k] = r[j++];
		}
	}
}

void mergeSort(int a[], int n, int left, int right) {
	if (left+1 < right) {
		int mid = (left + right) / 2;
		mergeSort(a, n, left, mid);
		mergeSort(a, n, mid, right);
		merge(a, n, left, mid, right);
	}
}


int main() {
	int a[Max], n, i;
	cnt = 0;
	cin >> n;
	rep(i, n) cin >> a[i];

	mergeSort(a, n, 0, n);
	rep(i, n) {
		if (i) cout << " ";
		cout << a[i];

	}
	cout << endl;
	cout << cnt << endl;
	return 0;
}
