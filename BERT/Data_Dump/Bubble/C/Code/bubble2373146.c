#include<stdio.h>
int main()
{
  int A[100],N,i,j,k,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
      for(j=i;j>0;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      k=A[j-1];
	      A[j-1]=A[j];
	      A[j]=k;
	      count++;
	    }
	  else break;
	}
    }
  for(i=0;i<N-1;i++) printf("%d ",A[i]);
  printf("%d\n%d\n",A[N-1],count);
  return 0;
}
