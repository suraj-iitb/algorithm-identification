#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int idx = i;
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[idx]) {
				idx = j;
			}
		}
		if (idx != i) {
			int t = a[i];
			a[i] = a[idx];
			a[idx] = t;
			cnt++;
		}
	}
	rep(i, n) {
		cout << a[i];
		if (i == n - 1) cout << endl;
		else cout << " ";
	}
	cout << cnt << endl;
	return 0;
}
