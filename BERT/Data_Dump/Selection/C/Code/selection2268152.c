#include<stdio.h>
int main()
{
  int i,j,N,A[100],x,n=0,minj;

  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }

  for(i=0;i<=N-1;i++)
    {
      minj=i;
      for(j=i;j<=N-1;j++)
	{
	  if(A[j]<A[minj])
	    {
	      minj=j;
	            	    }
	}

      x=A[i];
      A[i]=A[minj];
      A[minj]=x;
      if(A[i]<A[minj]) n++;

    }
  for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n%d\n",A[N-1],n);

  return 0;
}