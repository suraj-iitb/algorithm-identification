#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a[100], cnt = 0, minv = 100, p;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (minv > a[j]) {
        minv = a[j];
        p = j;
      }
    }
    if (a[i] != minv) {
      a[p] = a[i];
      a[i] = minv;
      cnt++;
    }
    minv = 100;
  }
  for (int i = 0; i < n; i++) {
    i == n - 1 ? printf("%d\n", a[i]) : printf("%d ", a[i]);
  }
  printf("%d\n", cnt);
  return 0;
}

