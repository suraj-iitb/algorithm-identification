#include<stdio.h>
int main()
{
  int n, a[100], i, j, minj, tmp, count = 0;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
    }
  for(i = 0; i < n; i++)
    {
      minj = i;
      for(j = i; j < n; j++)
	{
	  if(a[j] < a[minj])
	    {
	      minj = j;
	    }
	}
      if(a[i] > a[minj])
	{
	  count++;
	}
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
    }
  for(i = 0; i < n - 1; i++)
    {
      printf("%d ", a[i]);
    }
  printf("%d\n", a[n-1]);
  printf("%d\n", count);
  return 0;
}

