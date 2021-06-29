#include<stdio.h>
#define MAX 100

int main()
{
  int n, i, j, temp, count=0, a[MAX];
  scanf("%d", &n);
  
  for( i=0; i<n; i++)
    {
      scanf("%d", &a[i]);
    }

  for (i = 0; i < n - 1; i++)
    {
      for (j = n - 1; j >= i + 1; j--)
	{  
	  if (a[j] < a[j-1])
	    {
	      temp = a[j];
	      a[j] = a[j-1];
	      a[j-1] = temp;
	      count++;
	    }
	}
    }
  
  for(i = 0; i < n-1; i++)
    {
      printf("%d ", a[i]);
    }
  printf("%d\n", a[n-1]);
  printf("%d\n", count);

  return 0;
}

