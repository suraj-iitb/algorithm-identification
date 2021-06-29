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

int ans;

void merge(vi &a, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;
    vi l(n1+1), r(n2+1);
    rep(i, n1) l[i] = a[left+i];
    rep(i, n2) r[i] = a[mid+i];
    l[n1] = INT_MAX; r[n2] = INT_MAX;
    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        ans++;
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
        }
    }
}

void mergesort(vi &a, int left, int right) {
    if (left + 1 < right) {
        int mid = (left + right) >> 1;
        mergesort(a, left, mid);
        mergesort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];
    mergesort(a, 0, n);
    rep(i, n) cout << a[i] << (i == n-1 ? '\n' : ' ');
    cout << ans << endl;
}

