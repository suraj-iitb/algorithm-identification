#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)

const ll MOD = (ll)1e9 + 7;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n; cin >> n;
  vll v(n);
  ll ans = 0;
  REP(i, n) cin >> v.at(i);
  REP(i, n) {
    for (ll j=n-1; j>i; j--) {
      if (v.at(j) < v.at(j-1)) {
        swap(v.at(j), v.at(j-1));
        ans++;
      }
    }
  }
  cout << v.at(0);
  rep(i, 1, n) cout << ' ' << v.at(i);
  cout << endl;
  cout << ans << endl;
  return 0;
}

