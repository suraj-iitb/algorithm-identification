#include<stdio.h>
#define MAX 100

int main()
{
  int n, i, j, temp, min, flag=0, count=0, a[MAX];
  scanf("%d", &n);
  
  for( i=0; i<n; i++)
    {
      scanf("%d", &a[i]);
    }
  
  for (i = 0; i < n-1; i++)
    {
      min = i;
      for (j = i + 1; j < n; j++)
	{
	  if (a[j] < a[min])
	    {
	      min = j;
	      flag = 1;
	    } 
	}
      if(flag)
	{
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
      count++;
      flag = 0;
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

