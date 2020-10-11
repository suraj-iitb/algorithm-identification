#include <stdio.h>
#define N 100

int main()
{
  int a[N],n,i,j,minj,b;
  int cnt=0;

  scanf("%d",&n);
  for(i=0 ; i<n ;i++)
    {
      scanf("%d",&a[i]);
    }

  for(i=0 ; i<n ;i++)
    {
      minj=i;
      for(j=i ; j<n ; j++)
	{
	  if(a[j]<a[minj])
	    {
	      minj = j;
	    }
	}
      
      if(i != minj)
	{
	  b=a[i];
	  a[i] = a[minj];
	  a[minj] = b;
	  cnt++;
	}
    }

  for(i=0 ; i<n-1 ; i++)
    {
      printf("%d ",a[i]);
    }
  printf("%d\n%d\n",a[n-1],cnt);
  
  return 0;
}

