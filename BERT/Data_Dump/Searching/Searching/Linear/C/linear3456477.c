#include <stdio.h>

int main()
{
  int n, q;
  int s[10000];
  int t[500];
  int count = 0;

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &s[i]);
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d", &t[i]);
    s[n] = t[i];
    int j;
    for (j = 0; s[j] != t[i]; j++);
    if (j != n)
      count++;
  }
  printf("%d\n", count);
  
  return 0;
}
  


  

