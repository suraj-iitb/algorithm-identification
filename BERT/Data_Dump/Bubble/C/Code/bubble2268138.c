#include <stdio.h>

void swap(int *,int *);
int main()
{
  int i,j,N,count=0;
  int a[100];
  
  scanf("%d",&N);
  for (i=0;i<N;i++)
    {
      scanf("%d",&a[i]);
    }

  for(i=0;i<N;i++)
    {
      for(j=N-1;j>i;j--)
	{
	  if(a[j]<a[j-1])
	    {
	      swap(&a[j],&a[j-1]);
	      count++;
	    }
	}
    }
  for(i=0;i<N;i++)
    {
      printf("%d",a[i]);
      if(i!=N-1) printf(" ");
    }
  printf("\n");
  
  printf("%d\n",count);
  
  return 0;
}

void swap(int *x ,int *y)
{
  int z;
  
  z=*x;
  *x=*y;
  *y=z;
}
