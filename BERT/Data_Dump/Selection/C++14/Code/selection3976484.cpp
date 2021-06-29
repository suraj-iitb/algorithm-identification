#include<bits/stdc++.h>
#include <array>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
using LL = long long;
using ULL = unsigned long long;


void solve() {
	int n; cin >> n;
	int a[100]; rep(i, n) cin >> a[i];

	int swaps = 0;
	for (int i = 0; i < n; i++) {
		int mIdx = i;
		for (int j = i; j < n; j++) {
			if (a[j] < a[mIdx]) mIdx = j;
		}
		if (i != mIdx) {
			swaps++;
			swap(a[i], a[mIdx]);
		}
	}

	rep(i, n) {
		if (i != 0) cout << " ";
		cout << a[i];
	} cout << endl;

	cout << swaps << endl;
}

int main() {

	solve();

	return 0;
}

