#include <stdio.h>

int linear (int S[], int n, int key) {
  int i = 0; int f;
  S[n] = key;
  while (S[i] != key) {
    i++;
  }
  f = (i != n) ? 1 : 0;
  return f;
}

int main (void) {
  int n, q, i, key, cnt = 0;
  int S[10000];
  scanf("%d", &n);
  for (i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for (i = 0; i < q; ++i) {
    scanf("%d", &key);
    if (linear (S, n, key)) {
      cnt++;
    }
  }
  printf("%d\n", cnt);
}

