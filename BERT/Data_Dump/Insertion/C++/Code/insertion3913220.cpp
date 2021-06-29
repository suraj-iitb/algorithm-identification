#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		cin >> vec.at(i);
		cout << vec.at(i);
		if (i != n - 1)cout << ' ';
	}
	cout << endl;
	for (int i = 1; i < n; i++) {
		int v = vec.at(i);
		int j = i - 1;
		while (j >= 0 && vec.at(j) > v) {
			vec.at(j + 1) = vec.at(j);
			j--;
		}
		vec.at(j + 1) = v;
		for (int k = 0; k < n; k++) {
			cout << vec.at(k);
			if (k != n - 1) cout << ' ';
		}
		cout << endl;
	}
}
