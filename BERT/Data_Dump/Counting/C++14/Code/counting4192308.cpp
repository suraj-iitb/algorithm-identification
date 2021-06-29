#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e18;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}
ll factorial(ll n) {
  if (n == 1) {
    return 1;
  }
  ll ans = factorial(n-1);
  return ans*n;
}
ll gcd(ll a, ll b) {
  if (a < b) {
    ll tmp = a;
    a = b;
    b = tmp;
  }
  ll r = a%b;
  while(r != 0) {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}
ll lcm(ll a, ll b) {
  return (a/gcd(a, b))*b;
}

int main() {
  ll n;
  cin >> n;
  vector <ll> a(n+1), b(n+1);
  vector <ll> c(10001, 0);
  rep(i, n) cin >> a.at(i+1);
  rep(i, n) c.at(a.at(i+1))++;
  for (ll i = 1; i < c.size(); i++) {
    c.at(i) += c.at(i-1);
  }
  for (ll i = n; i >= 1; i--) {
    b.at(c.at(a.at(i))) = a.at(i);
    c.at(a.at(i))--;
  }
  for (ll i = 1; i < n+1; i++) {
    if (i-1) {
      cout << ' ' << b.at(i);
    } else {
      cout << b.at(i);
    }
  }
  cout << endl;
}
