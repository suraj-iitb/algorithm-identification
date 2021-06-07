#include <stdio.h>
int main()
{
  int S[10000], T[500], n, q, i, j, count = 0;

  scanf("%d",&n);
  for (i = 0; i < n; i++)
    scanf("%d",&S[i]);
  scanf("%d",&q);
  for (i = 0; i < q; i++){
    scanf("%d",&T[i]);
    j = 0;
    while (S[j] != T[i] && j < n)
      j++;
    if (j < n)
      count++;
  }
  printf("%d\n",count);
  
  return 0;
}

