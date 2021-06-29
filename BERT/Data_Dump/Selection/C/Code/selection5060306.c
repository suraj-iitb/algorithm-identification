#include<stdio.h>
#include<stdlib.h>

int main()
{
  int N,i,j,v,minj,count=0;
  int *A;

  scanf("%d",&N);
  A=(int *)malloc(sizeof(int)*N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }

  for(i=0;i<N;i++)
    {
      minj=i;
      for(j=i;j<N;j++)
	{
	  if(A[j]<A[minj]) minj=j;
	}
      if(A[i]!=A[minj])
	{
	  v=A[i];
	  A[i]=A[minj];
	  A[minj]=v;
	  count++;
	}
      
    }

  for(i=0;i<N-1;i++) printf("%d ",A[i]);
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  




  return 0;
}

