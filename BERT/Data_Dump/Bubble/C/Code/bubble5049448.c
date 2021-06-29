#include<stdio.h>
#include<stdlib.h>

#define N 101

int main()
{
  int i,a[N],l,j,count=0,k;

  scanf("%d",&l);
  
  if(l < 1 || l > 100)exit(2);
  
  for(i = 0;i < l;i++)
    {
      scanf("%d",&a[i]);
    }

  for(i = 0;i < (l*l-l)/2;i++)
    {
      for(j = l-1;j > 0;j--)
	{
	  if(a[j] < a[j-1])
	    {
	      k = a[j-1];
	      a[j-1] = a[j];
	      a[j] = k;
	      count++;
	    }
	}
    }
      
  printf("%d",a[0]);
  for(i = 1;i < l;i++)printf(" %d",a[i]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}
