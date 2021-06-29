#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

void InsertionSort(vector <ll> A, ll n) {
  for (ll i = 1; i < n; i++) {
    ll v = A.at(i);
    ll j = i-1;
    while (j>=0 && A.at(j)>v) {
      A.at(j+1) = A.at(j);
      j--;
    }
    A.at(j+1) = v;
    rep(i, n) {
      if (i) cout << ' ' << A.at(i);
      else cout << A.at(i);
    }
    cout << endl;
  }
  return;
}

int main() {
  ll n; cin >> n;
  vector <ll> v(n);
  rep(i, n) {
    cin >> v.at(i);
    if (i) cout << ' ' << v.at(i);
    else cout << v.at(i);
  }
  cout << endl;
  InsertionSort(v, n);
}
