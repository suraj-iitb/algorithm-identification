#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vc = vector<char>;
using vb = vector<bool>;
using vs = vector<string>;
using vll = vector<long long>;
using vp = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vvc = vector<vector<char>>;
using vvll = vector<vector<long long>>;
template<class T> inline bool chmax(T &a, T b) { if (a<b) {a=b; return 1;} return 0;}
template<class T> inline bool chmin(T &a, T b) { if (b<a) {a=b; return 1;} return 0;}

int selectionsort(vi &a, int n) {
    int cnt = 0;
    rep(i, n) {
        int minj = i;
        for (int j = i; j < n; ++j) {
            if (a[j] < a[minj]) minj = j;
        }
        if (minj != i) {
            cnt++;
            swap(a[i], a[minj]);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    int ans = selectionsort(a, n);
    rep(i, n) cout << a[i] << (i == n-1 ? '\n' : ' ');
    cout << ans << endl;
}

