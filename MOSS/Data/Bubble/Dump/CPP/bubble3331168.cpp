#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stdio.h>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <math.h>
#include <iomanip>
using namespace std;
#define Would
#define you
const int INF = 999999999;
const int MOD = 1e9 + 7;
const double pi = 3.141592653589793238;

int n, k[105], ans;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) { cin >> k[i]; }
	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j > i; --j) {
			if (k[j] < k[j - 1]) {
				swap(k[j - 1], k[j]);
				++ans;
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << k[i];
		if (i != n - 1) { cout << " "; }
		else { cout << endl; }
	}
	cout << ans << endl;
}

