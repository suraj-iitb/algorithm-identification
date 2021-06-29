#include <bits/stdc++.h>
using namespace std;
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
#define P(x) cout << (x) << endl
#define p(x) cout << (x)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define vv(type, c, m, n, i) vector<vector<type>> c(m, vector<type>(n, i));
#define rep(i,a,n) for(int i=(a), i##_len=(n); i<i##_len; ++i)
#define rrep(i,a,n) for(int i=(a); i>n; --i)
#define len(x) ((int)(x).size())
#define mp make_pair
#define eb emplace_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<long long> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
inline void bubbleSort(vi a, int n) {
	bool flg = true;
	int cnt = 0;
	while(flg) {
		flg = false;
		rrep(j, n - 1, 0) {
			if(a[j] < a[j - 1]) {
				swap(a[j], a[j - 1]);
				flg = true;
				++cnt;
			}
		}
	}
	rep(i, 0, n) {
		cout << a[i] << (i == n - 1 ? "\n" : " ");
	}
	P(cnt);
}
int main() {
	int n; cin >> n;
	vi v(n); rep(i, 0, n) cin >> v[i];
	bubbleSort(v, n);
	return 0;
}
