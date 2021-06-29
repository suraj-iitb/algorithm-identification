#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
using ll = long long;
using P = pair<int, int>;

tuple<int, vector<int>> selectionSort(vector<int> a, int n){
  int swaps = 0;
  for (int i=0; i<n; i++) {
    int minj = i;
    for (int j=i; j<n; j++) {
      if (a[j] < a[minj]) {
	minj = j;
      }
    }
    if (a[minj] == a[i]) continue;
    int tmp = a[minj];
    a[minj] = a[i];
    a[i] = tmp;
    swaps++;
  }
  return forward_as_tuple(swaps, a);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<int> ans;
  int times;
  tie(times, ans) = selectionSort(a, n);
  rep(i, n) printf("%d%c", ans[i], i == n-1 ? '\n':' ');
  cout << times << endl;
  return 0;
}

