#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, minj, cnt = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
	}
	for (int i = 0; i < n; i++) {
		minj = i;
		for (int j = i; j < n; j++) {
			if (a.at(j) < a.at(minj)) {
				minj = j;
			}
		}
		if (minj != i) {
			swap(a.at(i), a.at(minj));
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a.at(i);
		if (i == n - 1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
	cout << cnt << endl;
}
