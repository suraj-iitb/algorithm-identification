#include <stdio.h>
#define N 100
#define MAX 1000

int  main()
{
  int i, j, n, key, a[N];
  
  if((scanf("%d",&n)) > N)return 0;
  for(i = 0; i < n; i++)
    {
      if((scanf("%d", &a[i])) > MAX)return 0;
    }

  for( j = 1; j <= n; j++)
    {
      for( i = 0; i < n; i++)
	{
	  printf("%d", a[i]);
	  
	  if(i < n-1)printf(" ");
	  else printf("\n");
	}
      if(j == n)continue;
      
      key = a[j];
      
      for(i = j-1; i >= 0 && a[i] > key; i--)
	{
	  a[i+1] = a[i];
	}
      a[i+1] = key;
    }
  
  return 0;
}

