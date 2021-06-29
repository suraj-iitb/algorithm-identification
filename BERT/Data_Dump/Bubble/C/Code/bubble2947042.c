#include<stdio.h>
int main()
{
  int i, j, n, a[100], tmp, flag, count = 0;
  flag = 1;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    {
      scanf("%d", &a[i]);
    }
  while(flag)
    {
      flag = 0;
      for(j = n - 1; j >= 1; j--)
	{
	  if(a[j] < a[j-1])
	    {
	      tmp = a[j-1];
	      a[j-1] = a[j];
	      a[j] = tmp;
	      flag = 1;
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

