#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353;
const int INF = 1000000005;

void insertionSort(vector<int> &a, int n) {
  FOR(i, 1, n) {
    int m = a[i];
    FORR(j, i-1, -1) {
      if (j == -1) a[0] = m;
      else if (m < a[j]) {
        a[j+1] = a[j];
      }
      else {
        a[j+1] = m;
        break;
      }
    }
    rep(j, n) {
      if (j) cout << " ";
      cout << a[j];
    }
    cout << endl;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) {
    cin >> a[i];
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  insertionSort(a, n);

  
  return 0;
}
