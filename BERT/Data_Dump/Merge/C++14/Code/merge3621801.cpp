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
vll s(500000);

ll merge(ll l, ll m, ll r) {
  ll n1 = m - l;
  ll n2 = r - m;
  vll lv(n1 + 1, HIGHINF), rv(n2 + 1, HIGHINF);
  REP(i, n1) lv.at(i) = s.at(l + i);
  REP(i, n2) rv.at(i) = s.at(m + i);
  ll i = 0, j = 0, com = 0;
  rep(k, l, r) {
    if (lv.at(i) <= rv.at(j)) s.at(k) = lv.at(i++);
    else s.at(k) = rv.at(j++);
    com++;
  }
  return com;
}

ll mergeSort(ll l, ll r) {
  ll ans = 0;
  if (l + 1 < r) {
    ll mid = (l + r) / 2;
    ans += mergeSort(l, mid);
    ans += mergeSort(mid, r);
    ans += merge(l, mid, r);
  }
  return ans;
}

int main() {
  cin >> n;
  REP(i, n) cin >> s.at(i);
  ll ans = mergeSort(0, n);
  REP(i, n) {
    cout << s.at(i);
    if (i != n-1) cout << ' ';
  }
  cout << endl;
  cout << ans << endl;
  return 0;
}

