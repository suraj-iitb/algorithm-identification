#include <stdio.h>

int main()
{
  int i, j, a[100], n, minj, count = 0, temp, b = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++)
    {
      scanf("%d",&a[i]);
    }

  for(i = 0; i < n; i++)
    {
      minj = i;
      for(j = i; j < n; j++)
	{
	  if(a[j] < a[minj])
	    {
	      minj = j;
	      b++;
	    }
	}
      if(b != 0)
	{
	  temp = a[i];
	  a[i] = a[minj];
	  a[minj] = temp;
	  count++;
	  b = 0;
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

