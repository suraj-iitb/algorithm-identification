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

// const ll LL_INF = 1LL<<60;

template <class T> inline void chmin(T& a, T b) {if (a > b) {a = b;}}
template <class T> inline void chmax(T& a, T b) {if (a < b) {a = b;}}

using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> a(N, 0);
    rep(i, N) cin >> a[i];

    rep(j, N) {
        cout << a[j];
        if (j != N-1) cout << " ";
        else cout << "\n";
    }
    reps(i, 1, N) {
        ll key = a[i];
        // a[0:i-1]の適切な場所に挿入
        ll j = i-1;
        while (a[j]>key) {
            a[j+1] = a[j];
            j--;
            if (j < 0) break;
        }
        // a[j]<=keyとなったとき
        a[j+1] = key;

        rep(j, N) {
            cout << a[j];
            if (j != N-1) cout << " ";
            else cout << "\n";
        }
    }
}
