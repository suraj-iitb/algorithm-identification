#include<stdio.h>

int main()
{
  int i, j, n, m, x=0, a[100];

  scanf("%d", &n);
  for(i=0; i<n; i++)
    {
      scanf("%d", &a[i]);
    }

  for(i=0; i<n; i++)
    {
      for(j=n-1; j>i; j--)
	{
	  if(a[j]< a[j-1])
	    {
	      m = a[j];
	      a[j] = a[j-1];
	      a[j-1] = m;
	      x++;
	    }
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
