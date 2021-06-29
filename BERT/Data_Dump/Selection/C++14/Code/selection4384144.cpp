#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)n; i++)

using namespace std;
using ll = long long;

int selection_sort(int *a, int n) {
  int cnt = 0;

  for (int i = 0; i < n; i++) {
    int minj = i;

    for (int j = i; j < n; j++) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }

    if (minj != i) {
      int v = a[i];
      a[i] = a[minj];
      a[minj] = v;
      cnt++;
    }
  }

  return cnt;
}

int main() {
  int n;
  cin >> n;

  int a[n];
  rep(i, n) cin >> a[i];

  int cnt;
  cnt = selection_sort(a, n);

  rep(i, n) {
    cout << a[i];
    if (i < n - 1)
      cout << " ";
    else
      cout << endl;
  }

  cout << cnt << endl;

  return 0;
}

