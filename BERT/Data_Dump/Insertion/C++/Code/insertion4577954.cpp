#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, v, j;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a.at(i);
	}
	for (int i = 1; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			cout << a.at(k);
			if (k == n - 1) {
				cout << endl;
			} else {
				cout << " ";
			}
		}
		v = a.at(i);
		j = i - 1;
		while (j >= 0 && a.at(j) > v) {
			a.at(j + 1) = a.at(j);
			j--;
		}
		a.at(j + 1) = v;
	}
	for (int i = 0; i < n; ++i) {
		cout << a.at(i);
		if (i == n - 1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
}
