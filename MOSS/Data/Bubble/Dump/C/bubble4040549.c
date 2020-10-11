#include <stdio.h>

int main()
{
  int i, j, a[100], n, count = 0, temp, flag = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%d",&a[i]);
    }

  for(i = 0; i < n-1; i++)
    {
      if(a[i] > a[i+1])flag = 1;
    }

  while(flag == 1)
    {
      flag = 0;
      
      for(i = 0; i < n; i++)
	{
	  for(j = n-1; j > i; j--)
	    {
	      if(a[j] < a[j-1])
		{
		  temp = a[j];
		  a[j] = a[j-1];
		  a[j-1] = temp;
		  count++;
		  flag = 1;
		}
	    }
	}
    }
  
  for(i = 0; i < n-1; i++)
    {
      printf("%d ",a[i]);
    }
  
  printf("%d\n",a[n-1]);
  printf("%d\n",count);
  
  return 0;
}

