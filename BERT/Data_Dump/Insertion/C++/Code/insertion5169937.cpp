#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define ll long long
#define rep(i, n) for (int i = (0); i < (n); ++i)
using namespace std;

int main() {
  ll n;
  cin >> n;
  vector<ll> v(n);
  rep(i,n-1){
      ll input;
      cin >> input;
      v[i] = input;
      cout << input << ' ';
  }
  cin >> v[n-1];
  
  cout << v[n-1] << endl;

  for (int i = 1; i < n; ++i) {
    ll a = v[i];
    ll j = i - 1;
    while (j >= 0 && v[j] > a) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = a;
    rep(k, n-1) { cout << v[k] << ' '; }
    cout << v[n-1]<<endl;
  }

  return 0;
}
