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

int bubble_sort(vi &a, int n) {
    int cnt = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = n-1; j >= 1; j--) {
            if (a[j] < a[j-1]) {
                swap(a[j], a[j-1]);
                cnt++;
                flag = true;
            }
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
    int ans = bubble_sort(a, n);
    rep(i, n) cout << a[i] << (i == n-1 ? '\n' : ' ');
    cout << ans << endl;
}

