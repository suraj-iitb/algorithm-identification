#include <stdio.h>
#define N 100

int main()
{
  int n,i,j,v,r;
  int a[N];

  scanf("%d",&n);
  for(i=0 ; i<n ; i++)
    {
      scanf("%d",&a[i]);
    }

   for(r=0 ; r<n-1 ; r++)
	{
	  printf("%d ",a[r]);
	}
   printf("%d\n",a[n-1]);

  for(i=1 ; i<n ; i++)
    {
      v = a[i];
      j = i-1;
      while(j>=0 && a[j] > v)
	{
	  a[j+1] =a[j];
	  j--;
	}
      a[j+1] = v;

      for(r=0 ; r<n-1 ; r++)
	{
	  printf("%d ",a[r]);
	}
      printf("%d\n",a[n-1]);
      
    }

  return 0;
}

