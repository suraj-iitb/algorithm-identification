#include<stdio.h>
int main()
{
  int a[1000], n, i, j, k, v;
  scanf("%d", &n);
  for(k = 0; k < n; k++)
    {
      scanf("%d",&a[k]);
    }
  for(k = 0; k < n-1; k++)
    {
      printf("%d ",a[k]);
    }
  printf("%d\n", a[n-1]);
  for(i = 1; i < n; i++)
    {
      v = a[i];
      j = i - 1;
      while (j >= 0 && a[j] > v)
	{
	  a[j+1] = a[j];
	  j--;
	  a[j+1] = v;
	}
      for(k = 0; k < n-1; k++)
	{
	  printf("%d ",a[k]);
	}
      printf("%d\n", a[n-1]);
    }
  return 0;
}

