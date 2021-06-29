#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

int selectionSort (vector<int>& a) {
  int swaps = 0;
  for (int i = 0; i < sz(a); i++) {
    int mn = i;
    for (int j = i + 1; j < sz(a); j++) {
      if (a[j] < a[mn]) mn = j;
    }
    if (mn != i) {
      swap(a[i], a[mn]);
      swaps++;
    }
  }
  return swaps;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int ans = selectionSort(a);
  for (int i = 0; i < n; i++)
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
  cout << ans << '\n';
}


