#include "bits/stdc++.h"

using ll = long long;

using namespace std;
#define int ll

// 0 -> a-1
#define rep(i, a) for (int i = 0; (i) < (int)(a); (i)++)
// a -> b-1
#define reps(i, a, b) for (int i = (int)(a); (i) < (int)(b); (i)++)
// a-1 -> 0
#define rrep(i, a) for (int i = (int)a - 1; (i) >= 0; (i)--)
// a-1 -> b
#define rreps(i, a, b) for (int i = (int)(a)-1; (i) >= (int)(b); (i)--)
#define MP(a, b) make_pair((a), (b))
#define PB(a) push_back((a))
#define all(v) (v).begin(), (v).end()
// next_permutation(all(v))
#define PERM(v) next_permutation(all(v))
/*sort(all(v));
(v).erase(unique(all(v)), v.end())*/
#define UNIQUE(v)                                                              \
	sort(all(v));                                                              \
	(v).erase(unique(all(v)), v.end())
#define CIN(type, x)                                                           \
	type x;                                                                    \
	cin >> x
#define YES(f)                                                                 \
	if ((f)) {                                                                 \
		cout << "YES" << endl;                                                 \
	} else {                                                                   \
		cout << "NO" << endl;                                                  \
	}
#define Yes(f)                                                                 \
	if ((f)) {                                                                 \
		cout << "Yes" << endl;                                                 \
	} else {                                                                   \
		cout << "No" << endl;                                                  \
	}
#define MINV(v) min_element(all(v))
#define MAXV(v) max_element(all(v))
#define MIN3(a, b, c) min(min(a, b), c)
#define MIN4(a, b, c, d) min(MIN3(a, b, c), d)
#define MIN5(a, b, c, d, e) min(MIN4(a, b, c, d), e)
#define MIN6(a, b, c, d, e, f) min(MIN5(a, b, c, d, e), f)
#define MAX3(a, b, c) max(max(a, b), c)
#define MAX4(a, b, c, d) max(MAX3(a, b, c), d)
#define MAX5(a, b, c, d, e) max(MAX4(a, b, c, d), e)
#define MAX6(a, b, c, d, e, f) max(MAX5(a, b, c, d, e), f)
// b is [a, c)
#define RANGE(a, b, c) ((a) <= (b) && (b) < (c))
// c is [a, e) && d is [b, f)
#define RANGE2D(a, b, c, d, e, f) (RANGE((a), (c), (e)) && RANGE((b), (d), (f)))
#define chmin(a, b) a = min(a, (b))
#define chmin3(a, b, c) a = MIN3(a, (b), (c))
#define chmin4(a, b, c, d) a = MIN4(a, (b), (c), (d))
#define chmin5(a, b, c, d, e) a = MIN5(a, (b), (c), (d), (e))
#define chmin6(a, b, c, d, e, f) a = MIN6(a, (b), (c), (d), (e), (f))
#define chmax(a, b) a = max(a, (b))
#define chmax3(a, b, c) a = MAX3(a, (b), (c))
#define chmax4(a, b, c, d) a = MAX4(a, (b), (c), (d))
#define chmax5(a, b, c, d, e) a = MAX5(a, (b), (c), (d), (e))
#define chmax6(a, b, c, d, e, f) a = MAX6(a, (b), (c), (d), (e), (f))
#define fcout cout << fixed << setprecision(12)

void print(const vector<int>& v) {
	rep(i, v.size()) {
		if (i) cout << " ";
		cout << v[i];
	}
	cout << endl;
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& x: v) cin >> x;
	print(v);
	reps(i, 1, n) {
		int val = v[i];
		int j = i - 1;
		while (j >= 0 && v[j] > val) {
			v[j+1] = v[j];
			j--;
		}
		v[j+1] = val;
		print(v);
	}
}

signed main()
{
	solve();
}

