#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define sz(x) (int)(x).size()

int bubbleSort (vector<int>& a) {
  int swaps = 0;
  for (int i = 0; i < sz(a); i++) {
    for (int j = sz(a) - 1; j > i; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        swaps++;
      }
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
  int ans = bubbleSort(a);
  for (int i = 0; i < n; i++)
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
  cout << ans << '\n';
}


