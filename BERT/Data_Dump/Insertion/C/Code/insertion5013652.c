#include <stdio.h>

int n, a[105];

int insertionsort(void) {
  for (int j = 0; j < n; j++) {
    int k = j;
    while (k > 0 && a[k] < a[k - 1]) {
      int temp = a[k];
      a[k] = a[k - 1];
      a[k - 1] = temp;
      k--;
    }
    for (int i = 0; i < n - 1; i++) {
      printf("%d ", a[i]);
    }
    printf("%d\n", a[n - 1]);
  }

  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  insertionsort();
  return 0;
}
