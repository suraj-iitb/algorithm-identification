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
  
  int n_swap = 0;
  rep(i, n - 1) {
    int minj = i;

    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) minj = j;
    }

    if (i != minj) {
      swap(a[i], a[minj]);
      n_swap++;
    }
  }

  rep(i, n) {
    cout << a[i];
    i != n - 1 ? cout << " " : cout << endl;
  }

  cout << n_swap << endl;
}

