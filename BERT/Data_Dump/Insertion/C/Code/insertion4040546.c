#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i, j, a[100], v, n;
  
  scanf("%d",&n);
  
  for(i = 0; i < n; i++)
    {
      scanf("%d",&a[i]);
    }
  
  for(i = 0; i < n; i++)
    {
      v = a[i];
      j = i - 1;
      
      while(j >= 0 && a[j] > v)
	{
	  a[j+1] = a[j];
	  j--;
	}
      
      a[j+1] = v;
      
      for(v = 0; v < n-1; v++)
	{
	  printf("%d ",a[v]);
	}
      printf("%d\n",a[v]);
    }  

  return 0;
}

