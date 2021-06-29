#include <bits/stdc++.h>
using namespace std;

int merge(vector<int>& v) {
	int n = v.size();
	int h = n / 2;
	if (n == 1) return 0;
	vector<int> L(v.begin(), v.begin() + h);
	vector<int> R(v.begin() + h, v.end());
	int res = merge(L) + merge(R) + n;
	L.push_back(2e9);
	R.push_back(2e9);
	int l = 0, r = 0;
	for (int i = 0; i < n; i++) {
		if (L[l] <= R[r]) {
			v[i] = L[l++];
		} else {
			v[i] = R[r++];
		}
	}
	return res;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x:a) cin >> x;
	int r = merge(a);
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl << r << endl;
}
