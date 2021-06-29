#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void out(vi &a) {
  rep(i, a.size() - 1) printf("%d ", a[i]);
  printf("%d\n", *prev(a.end()));
}

int main() {
  int n;
  cin >> n;

  vi a(n);
  rep(i, n) cin >> a[i];

  rep(i, n) {
    int v = a[i],
      j = i - 1;

    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }

    a[j + 1] = v;
    out(a);
  }
}

