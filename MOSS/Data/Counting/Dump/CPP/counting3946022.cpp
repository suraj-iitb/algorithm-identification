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
const int MAX = 10005;

int n, c[MAX];

void CountingSort(vector<int>& a, vector<int>& b, int k) {
  rep(i, k+1) c[i] = 0;
  rep(i, n) c[a[i]]++;
  
  rep(i, k) c[i+1] += c[i];
  repr(i, n-1) {
    b[c[a[i]]-1] = a[i];
    c[a[i]]--;
  }
}

int main() {
  cin >> n;
  vector<int> a(n), b(n);
  int k = 0;
  rep(i, n) {
    cin >> a[i];
    k = max(k, a[i]);
  }

  CountingSort(a, b, k);

  rep(i, n) {
    if (i) cout << " ";
    cout << b[i];
  }
  cout << endl;

  
  return 0;
}

