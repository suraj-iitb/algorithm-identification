#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

#define MAX_N 100

void print_lst_a(int *lst_a, int n) {
  rep(j, n - 1) cout << lst_a[j] << " ";
  cout << lst_a[n - 1] << endl;
}

int main() {
  int n, lst_a[MAX_N];
  cin >> n;
  rep(i, n) cin >> lst_a[i];

  print_lst_a(lst_a, n);
  for (int i = 1; i < n; i++) {
    int v = lst_a[i];
    int j = i - 1;
    while (j >= 0 && lst_a[j] > v) {
      lst_a[j + 1] = lst_a[j];
      j--;
    }
    lst_a[j + 1] = v;
    print_lst_a(lst_a, n);
  }

  return 0;
}

