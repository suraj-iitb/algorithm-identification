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
	for (int i = 0; i < n; i++) {
		int min_i = i;
		int v = vec.at(min_i);
		for (int j = i; j < n; j++) {
			if (vec.at(j) < vec.at(min_i)) {
				min_i = j;
			}
		}
		if (min_i != i) ans++;
		vec.at(i) = vec.at(min_i);
		vec.at(min_i) = v;
	}
	for (int i = 0; i < n; i++) {
		cout << vec.at(i);
		if (i != n - 1) cout << ' ';
	}
	cout << endl;
	cout << ans << endl;
}
