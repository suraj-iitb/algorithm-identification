#include <stdio.h>

int main(void)
{
  int n, q, t, cnt = 0;
  int s[10000];
  
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++)
    scanf("%d", &s[i]);
  
  scanf("%d", &q);
  
  while (q--) {
    scanf("%d", &t);
    for (int i = 0; i < n; i++)
      if (s[i] == t) {
        cnt++;
        break;
      }
  }
  
  printf("%d\n", cnt);
  
  return 0;
}
