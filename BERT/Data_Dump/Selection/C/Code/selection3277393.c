#include <stdio.h>
#define N 100

int main()
{
  int min,i,j,a[N],t=0,n,tmp;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&a[i]);

  for(i = 0;i < n;i++)
    {
      min = i;
      for(j = i;j < n;j++) if(a[j] < a[min]) min = j;

      if(a[i] != a[min])
	{
	  tmp = a[i];
	  a[i] = a[min];
	  a[min] = tmp;
	  t++;
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

