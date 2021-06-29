#include <bits/stdc++.h>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> a(n+1, 0);
	vector<int> b(n+1, 0);

	int maxx = 0;
	for (int i =1; i <= n; i++) {
		cin >> a[i];
		maxx = max(maxx, a[i]);
	}

	vector<int> c(maxx+1, 0);
	for (int i = 1; i <= n; i++) {
		c[a[i]]++;
	}

	for (int i = 1; i <= maxx; i++) {
		c[i]+=c[i-1];
	}

	for (int i = n ; i > 0; i--) {
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}

	for (int i = 1; i <= n; i++) {
		cout << b[i] << (i == n  ? "\n" : " ");
	}

}
