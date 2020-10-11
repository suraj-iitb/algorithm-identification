#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);

int main()
{
  int i,j,n,count=0;
  int *num;

  scanf("%d",&n);
  num=(int *)malloc(n*sizeof(int));

  for(i=0; i<n; i++)
    {
      scanf("%d",&num[i]);
    }

  for(i=0; i<n-1; i++)
    {
      for(j=n-1; j>i; j--)
	{
	  if(num[j-1]>num[j])
	    {
	      swap(&num[j],&num[j-1]);
	      count++;
	    }
	}
    }

  for(i=0; i<n; i++)
    {
      if(i>0)
	{
	  printf(" ");
	}
      printf("%d",num[i]);
    }
  printf("\n%d\n",count);

  return 0;
}

void swap(int *j,int *j_1)
{
  int temp;
  temp=*j;
  *j=*j_1;
  *j_1=temp;
}

