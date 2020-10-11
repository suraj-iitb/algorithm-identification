#include<stdio.h>

int main()
{
  int i, j, n, m, min, x=0, a[100];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      scanf("%d", &a[i]);
    }

  for(i=0; i<n; i++)
    {
      min=i;
      for(j=i; j<n; j++)
	{
	  if(a[j]<a[min])
	    min = j;
	}
      if(min != i)
	{
	  m = a[i];
	  a[i] = a[min];
	  a[min] = m;
	  x++;
	}
    }
  
  for(i=0; i<n; i++)
    {
      printf("%d", a[i]);
      if(i+1<n) printf(" ");
    }
  printf("\n%d\n", x);
      
  return 0;
}
