#include <stdio.h>
#include <stdlib.h>
#define N 10000

int main()
{
  int i, j;
  int n, q;
  int nl[N], s;
  int count = 0;

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      scanf("%d", &nl[i]);
    }

  scanf("%d", &q);
  for(i = 0; i < q; i++)
    {
      scanf("%d", &s);
      for(j = 0; j < n; j++)
	{
	  if(s == nl[j]) 
	    {
	      count++;
	      break;
	    }
	}
    }
  printf("%d\n", count);

  return 0;
}
