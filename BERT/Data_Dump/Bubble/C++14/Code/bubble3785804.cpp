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

void bubbleSort(int a[], int n) {
  bool flag = true;
  int count = 0;
  while (flag) {
    flag = false;
    FORR(i, n - 1, 0) {
      if (a[i] < a[i - 1]) {
        swap(a[i], a[i - 1]);
        count++;
        flag = true;
      }
    }
  }
  trace(a, n);
  cout << count << endl;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  REP(i, n) {
    cin >> a[i];
  }

  bubbleSort(a, n);

  return 0;
}
