#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <stdio.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (n); i++)
#define P pair<long,long>
#define INF 1000000000000000000
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long MOD = 1000000007;
using namespace std;
typedef long long ll;
map<int, int> mp;
//最大公約数
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
//最小公倍数
ll lcm(ll a, ll b) {
	ll g = gcd(a, b);
	return a / g * b;
}
class Union_Find {
private:
	vector<int> par;
	vector<int> rank;
public:
	Union_Find(int n) {
		rep(i, n) {
			par.push_back(i);
			rank.push_back(0);
		}
	}
	int find(int x) {
		if (par.at(x) == x) return x;
		else return par.at(x) = find(par.at(x));
	}
	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (rank.at(x) < rank.at(y)) {
			par.at(x) = y;
		}
		else {
			par.at(y) = x;
			if (rank.at(x) == rank.at(y)) rank.at(x)++;
		}
	}
	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; cin >> n;
	vector<int>a(n), b(n); rep(i, n) { cin >> a[i]; b[i] = a[i]; }
	sort(b.begin(), b.end());
	rep(i, n) {
		if (i == n - 1)cout << b[i] << endl;
		else cout << b[i] << " ";
	}
	bool flag = true;
	int i = 0;
	int cnt = 0;
	while (flag) {
		flag = false;
		for (int j = n - 1; j >= i + 1; j--) {
			if (a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flag = true;
				cnt++;
			}
		}
		i++;
	}
	cout << cnt << endl;
	return 0;
}
