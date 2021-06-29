#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<int> insertionSort(vector<int> a, int n) {
  for (int i=1; i<n; i++) {
    rep(k, n) printf("%d%c", a[k], k == n-1 ? '\n':' ');
    int v = a[i];
    int j = i - 1;
    while ((j >= 0) && (a[j] > v)) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
  }
  return a;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> ans = insertionSort(a, n);
  rep(i, n) printf("%d%c", ans[i], i == n-1 ? '\n':' ');
  return 0;
}

