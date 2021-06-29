#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

const ll MAX = (ll)pow(10, 5) + 1;

vector <pair <ll, char>> v(MAX), tmp(MAX);

ll partition(ll p, ll r) {
  ll x = v.at(r).first, i = p-1;
  for (ll j = p; j < r; j++) {
    if (v.at(j).first <= x) {
      i++;
      swap(v.at(i), v.at(j));
    }
  }
  swap(v.at(i+1), v.at(r));
  return i+1;
}

void quicksort(ll p, ll r) {
  if (p < r) {
    ll q = partition(p, r);
    quicksort(p, q-1);
    quicksort(q+1, r);
  }
  return;
}

void merge(ll left, ll mid, ll right) {
  ll n1 = mid-left, n2 = right-mid;
  vector <pair <ll, char>> L(n1+1), R(n2+1);
  rep(i, n1) L.at(i) = tmp.at(left+i);
  rep(i, n2) R.at(i) = tmp.at(mid+i);
  L.at(n1) = make_pair(INF, 'A'); R.at(n2) = make_pair(INF, 'A');
  ll i = 0, j = 0;
  for (ll k = left; k < right; k++) {
    if (L.at(i).first <= R.at(j).first) {
      tmp.at(k) = L.at(i);
      i++;
    } else {
      tmp.at(k) = R.at(j);
      j++;
    }
  }
  return;
}

void mergeSort(ll left, ll right) {
  if (left+1 < right) {
    ll mid = (left+right) / 2;
    mergeSort(left, mid); 
    mergeSort(mid, right);
    merge(left, mid, right);
  }
  return;
}

int main() {
  ll n; cin >> n;
  rep(i, n) cin >> v.at(i).second >> v.at(i).first;
  tmp = v;
  quicksort(0, n-1);
  mergeSort(0, n);
  bool flag = 1;
  rep(i, n) {
    if (tmp.at(i).second != v.at(i).second) flag = 0;
  }
  if (flag) cout << "Stable" << endl;
  else cout << "Not stable" << endl;
  rep(i, n) cout << v.at(i).second << ' ' << v.at(i).first << endl;
}
