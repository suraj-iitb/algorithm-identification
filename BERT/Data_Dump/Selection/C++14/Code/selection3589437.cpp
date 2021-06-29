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
  REP(i, n) cin >> v.at(i);
  ll ans = 0;
  REP(i, n) {
    ll mini = i;
    rep(j, i, n) {
      if (v.at(j) < v.at(mini)) mini = j;
    }
    swap(v.at(i), v.at(mini));
    if (mini != i) ans++;
  }
  cout << v.at(0);
  rep(i, 1, n) cout << ' ' << v.at(i);
  cout << endl;
  cout << ans << endl;
  return 0;
}

