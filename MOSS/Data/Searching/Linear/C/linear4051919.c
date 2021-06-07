#include <stdio.h>

int main()
{
  int s[10000], t[500], n, q, i, j, count = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%d",&s[i]);
    }

  scanf("%d",&q);

  for(i = 0; i < q; i++)
    {
      scanf("%d",&t[i]);
    }

  for(i = 0; i < q; i++)
    {
      j = 0;
      s[n] = t[i];
      while(s[j] != t[i])
	{
	  j++;
	}
      if(j != n)
	{
	  count++;
	  s[j] = -1;
	}
    }

  printf("%d\n",count);
  
  return 0;
}

