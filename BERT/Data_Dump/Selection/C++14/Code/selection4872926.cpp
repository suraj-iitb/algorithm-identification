#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

ll selectionSort(vector <ll> v, ll n) {
  ll res = 0;
  rep(i, n) {
    ll minj = i;
    for (ll j = i; j < n; j++) {
      if (v.at(j) < v.at(minj)) minj = j;
    }
    if (i != minj) {
      swap(v.at(i), v.at(minj));
      res++;
    }
  }
  rep(i, n) {
    if (i) cout << ' ' << v.at(i);
    else cout << v.at(i);
  }
  cout << endl;
  return res;
}

int main() {
  ll n; cin >> n;
  vector <ll> v(n);
  rep(i, n) cin >> v.at(i);
  cout << selectionSort(v, n) << endl;
}
