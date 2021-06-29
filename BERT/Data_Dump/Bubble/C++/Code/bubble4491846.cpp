#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int n;
  cin >> n;
  vector<int> lst_a(n, 0);
  rep(i, n) cin >> lst_a[i];

  bool flag = true;
  int sortd_idx = 0;
  int count_swap = 0;
  while (flag) {
    flag = false;
    rep(i, n - 1) {
      int idx = n - i - 1;
      if (lst_a[idx] < lst_a[idx - 1]) {
        int tmp = lst_a[idx - 1];
        lst_a[idx - 1] = lst_a[idx];
        lst_a[idx] = tmp;
        flag = true;
        count_swap++;
      }
    }
  }
  rep(i, n - 1) cout << lst_a[i] << " ";
  cout << lst_a[n - 1] << endl;
  cout << count_swap << endl;
  return 0;
}

