#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int ii = 0; ii < n - 1; ii++) {
		cout << a[ii] << " ";
	}
	cout << a[n - 1] << endl;
	int v;
	for (int i = 1; i < n; i++) {
		v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;

		for (int ii = 0; ii < n - 1; ii++) {
			cout << a[ii] << " ";
		}
		cout << a[n - 1] << endl;
	}

}
