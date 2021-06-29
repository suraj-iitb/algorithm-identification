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
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
				cnt++;
			}
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
