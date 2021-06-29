#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	int n;
	int ans = 0;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec.at(i);
	}
	bool flag = true;
	while (flag) {
		flag = false;
		for (int i = n - 1; i > 0; i--) {
			if (vec.at(i) < vec.at(i - 1)) {
				int t = vec.at(i);
				vec.at(i) = vec.at(i - 1);
				vec.at(i - 1) = t;
				ans++;
				flag = true;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << vec.at(i);
		if (i != n - 1) cout << ' ';
	}
	cout << endl;
	cout << ans << endl;
}
