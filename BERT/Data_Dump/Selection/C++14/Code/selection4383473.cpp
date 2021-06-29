#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

void selection_sort(int a[], int n) {
  int c = 0;
  rep(i, 0, n) {
    int minj = i;
    rep(j, i, n) {
      if (a[j] < a[minj])
        minj = j;
    }
    if (a[i] > a[minj]) {
      swap(a[i], a[minj]);
      c++;
    }
  }

  rep(i, 0, n) {
    if (i > 0)
      cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << c << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a[n];
  rep(i, 0, n) cin >> a[i];
  selection_sort(a, n);
}

