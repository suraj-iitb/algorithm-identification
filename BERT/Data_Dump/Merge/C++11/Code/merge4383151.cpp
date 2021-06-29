#pragma warning (disable :4996)
#include <bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
typedef long long ll;
const double PI = cos(-1.0);
const double eps = 1e-8;
#define For(i,n,m) for(ll i=n;i<=m;++i)

ll a[1000001], b[10000001];
ll n;
ll cnt;
void merge(ll le, ll mid, ll ri) {
	ll i = le, j = mid + 1, t = le;
	while (i <= mid && j <= ri) {
		if (a[i] <= a[j]) b[t++] = a[i++], ++cnt;
		else b[t++] = a[j++], ++cnt;
	}
	while (i <= mid) b[t++] = a[i++], ++cnt;
	while (j <= ri) b[t++] = a[j++], ++cnt;
	For(i, le, ri) a[i] = b[i];
}
void mergesort(ll le, ll ri) {
	if (le < ri) {
		ll mid = (le + ri) / 2;
		mergesort(le, mid);
		mergesort(mid + 1, ri);
		merge(le, mid, ri);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	For(i, 1, n) cin >> a[i];
	mergesort(1, n);
	For(i, 1, n) { if (i != 1) cout << " "; cout << a[i]; }
	cout << "\n" << cnt << "\n";
}
