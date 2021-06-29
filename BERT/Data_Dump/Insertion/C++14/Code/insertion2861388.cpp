#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a[100], tmp;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j > 0; j--) {
      if (a[j] >= a[j - 1]) {
        break;
      } else {
        tmp = a[j];
        a[j] = a[j - 1];
        a[j - 1] = tmp;
      }
    }
    for (int j = 0; j < n; j++) {
      j == n - 1 ? printf("%d\n", a[j]) : printf("%d ", a[j]);
    }
  }
  return 0;
}

