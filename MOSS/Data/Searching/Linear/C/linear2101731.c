#include <stdio.h>

int main(void)
{
  int n, s[10000];
  int q, t[500];
  int i, j, count = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &s[i]);
  scanf("%d", &q);
  for (i = 0; i < q; i++) scanf("%d", &t[i]);

  for (i = 0; i < q; i++) {
    for (j = 0; j < n; j++) {
      if (s[j] == t[i]) {
        count++;
        break;
      }
    }
  }
  printf("%d\n", count);

  return 0;
}
