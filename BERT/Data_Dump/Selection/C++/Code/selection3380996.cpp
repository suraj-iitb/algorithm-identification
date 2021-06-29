#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>

typedef long long ll;

#define reps(i, s, e) for (ll i = s; i < e; ++i)
#define rep(i, n) reps(i, 0, n)
#define rreps(i, s, e) for (ll i = e-1; i >= s; --i)
#define rrep(i, n) rreps(i, 0, n)

const ll LL_INF = 1LL<<60;

template <class T> inline void chmin(T& a, T b) {if (a > b) {a = b;}}
template <class T> inline void chmax(T& a, T b) {if (a < b) {a = b;}}

using namespace std;

template<class T> inline void sw(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T> inline ll selection_sort(vector<T>& a) {
    ll cnt = 0;
    ll n = a.size();
    rep(i, n-1) {
        ll argmin = i;
        reps(j, i+1, n) {
            if (a[j] < a[argmin]) argmin = j;
        }
        if (argmin != i) {
            sw<T>(a[i], a[argmin]);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];

    ll cnt = selection_sort(a);
    rep(i, n) {
        cout << a[i];
        if (i != n-1) cout << " ";
        else cout << "\n";
    }
    cout << cnt << endl;
}
