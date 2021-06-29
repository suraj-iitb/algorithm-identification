#include <bits/stdc++.h>
#define int long long
#define mod (int)(1e9+7)
#define inf (int)(3e18)
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<n;i++)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define PP pair<P,P>
#define all(v) v.begin(),v.end()
#define mkp make_pair
#define mkt make_tuple
#define prique(T) priority_queue<T,vector<T>,greater<T>>
#define vecunique(vec) sort(vec.begin(), vec.end());decltype(vec)::iterator result = std::unique(vec.begin(), vec.end());vec.erase(result, vec.end())
using namespace std;
template<class T> inline void chmax(T& a, T b) { a = max(a, b); }
template<class T> inline void chmin(T& a, T b) { a = min(a, b); }

bool prime(int x) {
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0)return false;
	}
	return x > 1;
}
int gcd(int x, int y) {
	if (y == 0)return x;
	return gcd(y, x % y);
}
int lcm(int x, int y) {
	return x / gcd(x, y) * y;
}
int kai(int x, int y) {
	int res = 1;
	for (int i = x - y + 1; i <= x; i++) {
		res *= i; res %= mod;
	}
	return res;
}
int mod_pow(int x, int y, int m) {
	int res = 1;
	while (y > 0) {
		if (y & 1) {
			res = res * x % m;
		}
		x = x * x % m;
		y >>= 1;
	}
	return res;
}
int comb(int x, int y) {
	if (y > x)return 0;
	return kai(x, y) * mod_pow(kai(y, y), mod - 2, mod) % mod;
}
int get_rand(int MIN, int MAX) {
	random_device rnd;
	mt19937_64 mt64(rnd());
	uniform_int_distribution<int>engine(MIN, MAX);
	return engine(mt64);
}
/*--------Library Zone!--------*/

int mergesort(vector<int>& a) {
	if (a.size() <= 1)return 0;
	int n = a.size();
	vector<int>b, c;
	rep(i, a.size()) {
		if (i < a.size() / 2)b.push_back(a[i]);
		else c.push_back(a[i]);
	}
	int res = 0;
	res += mergesort(b); res += mergesort(c);
	a.clear();
	int bi = 0, ci = 0;
	while (bi < b.size() || ci < c.size()) {
		if (bi < b.size() && (ci >= c.size() || b[bi] < c[ci])) {
			a.push_back(b[bi]); bi++;
		}
		else {
			a.push_back(c[ci]); ci++;
		}
		res++;
	}
	return res;
}
signed main() {
	int n; vector<int>v;
	cin >> n;
	rep(i, n) {
		int a; cin >> a; v.push_back(a);
	}
	int ans = mergesort(v);
	rep(i, n) {
		if (i)cout << " ";
		cout << v[i];
	}
	cout << endl << ans << endl;
}

