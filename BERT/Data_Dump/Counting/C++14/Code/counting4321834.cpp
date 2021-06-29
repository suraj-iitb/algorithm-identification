#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;

vector<int> countingSort(vector<int> a, int k, int n) {
  vector<int> res(n), c(k+1);
  
  rep(j,n) c[a[j]]++;

  for (int i=1; i<=k; i++) {
    c[i] = c[i] + c[i-1];
  }
  rep(i,k+1) c[i]--;

  for (int j=n-1; j>=0; j--) {
    res[c[a[j]]] = a[j];
    c[a[j]]--;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];

  vector<int> ans;
  ans = countingSort(a, *max_element(a.begin(), a.end()), n);
  rep(i,n) printf("%d%c", ans[i], (i == n-1?'\n':' '));
  return 0;
}

