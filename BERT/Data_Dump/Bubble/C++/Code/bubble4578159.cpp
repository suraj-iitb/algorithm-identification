#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, cnt = 0;
	cin >> n;
	bool flag = true;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a.at(i);
	}
	while (flag) {
		flag = false;
		for (int i = n - 1; i > 0; --i) {
			if (a.at(i) < a.at(i - 1)) {
				swap(a.at(i), a.at(i - 1));
				++cnt;
				flag = true;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a.at(i);
		if (i == n - 1) {
			cout << endl;
		} else {
			cout << " ";
		}
	}
	cout << cnt << endl;
}
