#include <stdio.h>

#define N 3000000

int n;

void count(int *, int);

int main() {
  int i, max = 0, a[N];

  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &a[i]);

  for (i = 1; i <= n; i++)
    if (max < a[i]) max = a[i];

  count(a, max + 1);

  return 0;
}
void count(int *a, int k) {
  int i, b[N], c[k + 1];

  for (i = 0; i <= k; i++) c[i] = 0;

  for (i = 1; i <= n; i++) c[a[i]]++;

  for (i = 1; i <= k; i++) c[i] = c[i] + c[i - 1];

  for (i = n; i >= 1; i--) {
    b[c[a[i]]] = a[i];
    c[a[i]]--;
  }
  for (i = 1; i < n; i++) printf("%d ", b[i]);
  printf("%d\n", b[n]);
}
