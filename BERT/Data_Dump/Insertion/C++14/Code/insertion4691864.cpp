#include <bits/stdc++.h>
using namespace std;

#define rep(i, u) for (int i = 0; i < u; i++)

using ll = long long;
using ull = unsigned long long;

int main() {
  int n;
  int a[100] = {};
  cin >> n;
  rep(i, n) cin >> a[i];

  rep(i, n) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    rep(i, n) {
      cout << a[i];
      if (i != n - 1) cout << ' ';
      else cout << endl; 
    }
  }
  return 0;
}

