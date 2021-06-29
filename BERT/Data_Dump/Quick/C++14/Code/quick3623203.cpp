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
V<P<char, ll>> a(100000);
V<P<char, ll>> b(100000);

void merge(ll l, ll m, ll r) {
  ll n1 = m - l;
  ll n2 = r - m;
  V<P<char, ll>> lv(n1+1, P<char, ll>(' ', HIGHINF)), rv(n2+1, P<char, ll>(' ', HIGHINF));
  REP(i, n1) lv.at(i) = b.at(l + i);
  REP(i, n2) rv.at(i) = b.at(m + i);
  ll i = 0;
  ll j = 0;
  rep(k, l, r) {
    if (lv.at(i).second <= rv.at(j).second) b.at(k) = lv.at(i++);
    else b.at(k) = rv.at(j++);
  }
}

void mergeSort(ll l, ll r) {
  if (l+1 < r) {
    ll mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid, r);
    merge(l, mid, r);
  }
}

ll partition(ll l, ll r) {
  P<char, ll> x = a.at(r-1);
  ll i = l-1;
  rep(j, l, r-1) {
    if (a.at(j).second <= x.second) {
      i++;
      P<char, ll> tmp = a.at(i);
      a.at(i) = a.at(j);
      a.at(j) = tmp;
    }
  }
  P<char, ll> tmp = a.at(i+1);
  a.at(i+1) = a.at(r-1);
  a.at(r-1) = tmp;
  return i+1;
}

void quickSort(ll l, ll r) {
  if (l < r) {
    ll q = partition(l, r);
    quickSort(l, q);
    quickSort(q+1, r);
  }
}

int main() {
  cin >> n;
  REP(i, n) {
    cin >> a.at(i).first >> a.at(i).second;
    b.at(i) = a.at(i);
  }
  quickSort(0, n);
  mergeSort(0, n);
  bool is_stable = true;
  REP(i, n) {
    if (a.at(i) != b.at(i)) {
      is_stable = false;
      break;
    }
  }
  if (is_stable) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
  REP(i, n) {
    cout << a.at(i).first << ' ' << a.at(i).second << endl;
  }
  return 0;
}

