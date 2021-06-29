#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;

  vi a(n);
  rep(i, n) cin >> a[i];

  bool flag = true;
  int n_swap = 0;
  while (flag) {
    flag = false;
    
    for (int i = n - 1; i > 0; i--) {
      if (a[i] < a[i - 1]) {
        swap(a[i], a[i - 1]);
        flag = true;
        n_swap++;
      }
    }
  }

  rep(i, n) {
    cout << a[i];
    if (i != n - 1) cout << " ";
    else cout << endl;
  }

  cout << n_swap << endl;
}

