#include <stdio.h>
#define N 100

int main()
{
  int a[N],n,i,j,t=0,tmp;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&a[i]);
  for(i = 0;i < n;i++)
    {
      for(j = n-1;j > i;j--)
	{
	  if(a[j] < a[j - 1])
	    {
	      tmp = a[j];
	      a[j] = a[j - 1];
	      a[j - 1] = tmp;
	      t++;
	    }
	}
    }
  
  for(i = 0;i < n;i++)
    {
      if(i > 0) printf(" ");
      printf("%d",a[i]);
    }
  
  printf("\n%d\n",t);

  return 0;
}

