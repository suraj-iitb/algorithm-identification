#include<iostream>
#include<string>
#include<algorithm>    
#include<cmath>
#include<map>
#include<vector>
#include<math.h>
#include<stdio.h>
#include<stack>
#include<queue>
#include<tuple>
#include<cassert>
#include<set>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
int test[345678];
signed main() {
	int n, a, mae = 0, sum = 0, ans = 0; cin >> n;
	for (int h = 0; h < n; h++) {
		cin >> test[h];
	}
	for (int h = 0; h < n; h++) {
		int b = h;
		while (b--) {
			if (b < 0) { break; }
			if (test[b] > test[b + 1]) {
				swap(test[b], test[b + 1]);
			}
			else { break; }
		}
		for (int i = 0; i < n; i++) {
			if (i == 0) { cout << test[i]; }
			else { cout << ' ' << test[i]; }
		}
		cout << endl;
	}
	return 0;
}
