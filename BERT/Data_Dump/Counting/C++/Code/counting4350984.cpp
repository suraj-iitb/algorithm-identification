#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <set>
using namespace std;

int main() {
	int n, a[2000001] = {}, b[2000001] = {}, c[10001] = {}, m = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i]]++;
		m = max(m, a[i]);
	}
	for (int i = 1; i <= m; i++) {
		c[i] += c[i - 1];
	}
	for (int i = n - 1; i >= 0;i--) {
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
	for (int i = 1; i <= n; i++) {
		if (i-1) cout << " ";
		cout << b[i];
	}
	cout << endl;
}
