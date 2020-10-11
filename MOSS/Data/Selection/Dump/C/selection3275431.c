#include <stdio.h>
#include <stdlib.h>

void swap(int *,int *);

int main()
{
  int i,j,n,flag=0,count=0,mimj=0;
  int *num;

  scanf("%d",&n);
  num=(int *)malloc(n*sizeof(int));

  for(i=0; i<n; i++)
    {
      scanf("%d",&num[i]);
    }

  //ここから並び換え作業//

  for(i=0; i<=n-2; i++)
    {
      mimj=i;
      for(j=i+1; j<=n-1; j++)
	{
	  if(num[j]<num[mimj])
	    {
	      mimj=j;
	    }
	}
      swap(&num[i],&num[mimj]);
      if(i!=mimj)
	{
	  count++;
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

