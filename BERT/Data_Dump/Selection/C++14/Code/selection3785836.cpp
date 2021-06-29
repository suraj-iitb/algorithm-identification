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

int selectionSort(int a[], int n) {
  int count = 0;
  REP(i, n) {
    int minJ = i;
    FOR(j, i, n) {
      if (a[j] < a[minJ]) {
        minJ = j;
      }
    }
    if (i != minJ) {
      swap(a[i], a[minJ]);
      count++;
    }
  }
  return count;
}

int main() {
  int n;
  cin >> n;
  int a[n];
  REP(i, n) {
    cin >> a[i];
  }

  int count = selectionSort(a, n);
  trace(a, n);
  cout << count << endl;
  return 0;
}
