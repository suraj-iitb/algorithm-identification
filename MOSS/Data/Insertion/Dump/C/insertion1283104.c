#include<stdio.h>

int main()
{
  int A[1000],i=0,N,v,j,n;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
     
    }
  for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[i]);
      for(i=1;i<N;i++)
    {
      v=A[i];
      j=i-1;
      while(j>=0&&A[j]>v)
	{
	  A[j+1]=A[j];
	    j--;
	    }
      A[j+1]=v;
      for(n=0;n<N-1;n++){
      printf("%d ",A[n]);
      }
      printf("%d\n",A[n]);
    }
  return 0;
}
