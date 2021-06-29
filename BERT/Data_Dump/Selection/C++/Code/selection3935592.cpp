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

int t = 0;

void selectionSort(vector<int> &a, int n) {
  int minj;
  rep(i, n) {
    minj = i;
    FOR(j, i, n) {
      if (a[j] < a[minj]) {
        minj = j;
      }
    }
    if (minj != i) {
      swap(a[i], a[minj]);
      t++;
    }
  }

  rep(i, n) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << t << endl;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  selectionSort(a, n);

  
  return 0;
}
