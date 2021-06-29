#include <bits/stdc++.h>
#define FOR(i, m, n) for (int i = m; i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i > 0; i--)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;

void trace(int a[], int n) {
  REP(i, n) {
    if (i > 0) cout << " ";
    cout << a[i];
  }
  cout << endl;
}

void insertionSort(int a[], int n) {
  int j, v;
  FOR(i, 1, n) {
    v = a[i];
    j = i - 1;
    while (j >= 0 && a[j] > v) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = v;
    trace(a, n);
  }
}

int main() {
  int n;
  cin >> n;
  int a[n];
  REP(i, n) {
    cin >> a[i];
  }
  trace(a, n);
  insertionSort(a, n);
  return 0;
}
