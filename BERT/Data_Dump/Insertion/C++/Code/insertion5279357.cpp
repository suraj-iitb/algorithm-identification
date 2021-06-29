#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void insertionSort(vector<int>&a, int&n) {
	for (int i = 1; i < n ; i++) {
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		rep(k, n) {
			cout << a[k];
			if (k == n-1)cout << endl;
			else cout << " ";
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n)cin >> a[i];

	rep(i, n) {
		if (i == n - 1)cout<< a[i] << endl;
		else cout << a[i] << " ";
	}
	insertionSort(a, n);
}
