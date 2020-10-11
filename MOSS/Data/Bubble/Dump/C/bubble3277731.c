#include <stdio.h>
#define N 100

int main()
{
  int a[N],n,i,j,flag,b;
  int cnt=0;

  scanf("%d",&n);
  for(i=0 ; i<n ;i++)
    {
      scanf("%d",&a[i]);
    }

  flag = 1;
  while(flag == 1)
    {
      flag = 0;
      for(j = n-1 ; j>0 ; j--)
	{
	  if(a[j] < a[j-1])
	    {
	      b=a[j];
	      a[j] = a[j-1];
	      a[j-1] = b;
	      
	      flag = 1;
	      cnt++;
	    }
	}
    }

  for(i=0 ; i<n-1 ; i++)
    {
      printf("%d ",a[i]);
    }
  printf("%d\n%d\n",a[n-1],cnt);
  
  return 0;
}

