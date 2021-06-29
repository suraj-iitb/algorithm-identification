#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int selectionSort(vector<int> &lst, int n) {
  int count_swp = 0;
  rep(i, n - 1) {
    int minj = i;
    for (int j = i; j < n; j++) {
      if (lst[j] < lst[minj]) minj = j;
    }
    if (minj != i) {
      swap(lst[minj], lst[i]);
      count_swp++;
    }
  }
  return count_swp;
}

int main() {
  int n;
  cin >> n;
  vector<int> lst_a(n, 0);
  rep(i, n) cin >> lst_a[i];

  int count_swp = selectionSort(lst_a, n);
  rep(i, n) {
    if (i > 0) cout << " ";
    cout << lst_a[i];
  }
  cout << endl;
  cout << count_swp << endl;
  return 0;
}

