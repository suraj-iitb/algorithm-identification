#include <stdio.h>
#include <stdlib.h>

#define k 10000

int main() {
  int i, j, n;
  scanf("%d", &n);
  int a[n + 1], b[n + 1], c[k + 1] = {0};

  for (i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    c[a[i]]++;
  }

  for (i = 1; i <= k; i++) {
    c[i] += c[i - 1];
  }

  for (j = n; j >= 1; j--) {
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }

  for (i = 1; i <= n; i++) {
    if (i > 1)  printf(" ");
    printf("%d", b[i]);
  }
  putchar('\n');

  return 0;
}

