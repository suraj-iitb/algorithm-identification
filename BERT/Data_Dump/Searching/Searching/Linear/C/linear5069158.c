#include <stdio.h>

int main()
{
  int i, j, n, q, S[10000], T[500], c=0;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf("%d",&S[i]);
    }
  scanf("%d",&q);
  for(i = 0; i < q; i++)
    {
      scanf("%d",&T[i]);
    }

  for(i = 0;i < q; i++)
    {
      j = 0;
      S[n] = T[i];
      while(S[j] != T[i])
	{
	  j++;
	}
      if(j != n) c++;
    }

  printf("%d\n",c);

  return 0;
}

