#include <stdio.h>

int main()
{
  int i, j, n, q, t, cnt=0;
  scanf("%d", &n);
  int s[n+1];
  for (i=0; i<n; i++) scanf("%d", s+i);
  scanf("%d", &q);
  for (i=0; i<q; i++) {
    scanf("%d", &t);
    s[n] = t;
    for (j=0; s[j]!=t; j++);
    if (j!=n) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}

