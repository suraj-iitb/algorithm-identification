#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define REP(i, n) for (ll i=0; i<(ll)n; ++i)
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)

const ll MOD = (ll)1e9 + 7;
const ll HIGHINF = (ll)1e18;

int main() {
  ll n; cin >> n;
  vll v(n);
  REP(i, n) cin >> v.at(i);
  cout << v.at(0);
  rep(i, 1, n) cout << ' ' << v.at(i);
  cout << endl;
  rep(i, 1, n) {
    ll k = v.at(i);
    ll j = i-1;
    while (j>=0 && v.at(j) > k) {
      v.at(j+1) = v.at(j);
      j--;
    }
    v.at(j+1) = k;
    cout << v.at(0);
    rep(j, 1, n) cout << ' ' << v.at(j);
    cout << endl;
  }
  return 0;
}

