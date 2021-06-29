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
	for (int i = 1; i < n; i++) {
		rep(k, n) {
			cout << a[k];
			if (k == n - 1) cout << endl;
			else cout << " ";
		}
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
	}
	rep(k, n) {
		cout << a[k];
		if (k == n - 1) cout << endl;
		else cout << " ";
	}
	return 0;
}
