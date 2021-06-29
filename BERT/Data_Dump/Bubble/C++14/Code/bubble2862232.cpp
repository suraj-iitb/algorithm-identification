#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, a[100], cnt = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = n - 1; i > 0; i--) {  
    for (int j = n - 1; j > 0; j--) {
      if (a[j] < a[j - 1]) {
        swap(a[j], a[j - 1]);
        cnt++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    i == n - 1 ? printf("%d\n", a[i]) : printf("%d ", a[i]);
  }
  printf("%d\n", cnt);
  return 0;
}

