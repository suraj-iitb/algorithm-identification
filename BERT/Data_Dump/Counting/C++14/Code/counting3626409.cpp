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

ll n;
vll a(2000000);

int main() {
  cin >> n;
  REP(i, n) cin >> a.at(i);
  vll count(10001, 0);
  REP(i, n) {
    count.at(a.at(i))++;
  }
  rep(i, 1, count.size()) {
    count.at(i) += count.at(i-1);
  }
  vll b(n);
  for (ll i=n-1; i>=0; i--) {
    b.at(count.at(a.at(i))-1) = a.at(i);
    count.at(a.at(i))--;
  }
  REP(i, n) {
    cout << b.at(i);
    if (i != n-1) cout << ' ';
  }
  cout << endl;
  return 0;
}

