#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

void display(int a[], int n) {
  rep(k, 0, n) {
    if (k > 0)
      cout << " ";
    cout << a[k];
  }
  cout << endl;
}

void insertionSort(int a[], int n) {
  rep(i, 1, n) {
    int v = a[i];
    int j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    display(a, n);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a[n];
  rep(i, 0, n) cin >> a[i];
  display(a, n);
  insertionSort(a, n);
}

