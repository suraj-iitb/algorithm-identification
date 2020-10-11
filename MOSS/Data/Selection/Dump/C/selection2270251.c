#include<stdio.h>

int main(){
  int i,j,N,count=0,minj=0,temp;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<=N-1;i++)
    {
      scanf("%d",&A[i]);
    }
  for(i = 0;i<=N-1;i++)
    {
      minj = i;
      for(j=i;j<=N-1;j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj =j;
	    }
	}
      if(minj != i)
	{
      temp = A[i];
      A[i]=A[minj];
      A[minj]=temp;
      count++;
	}
  }
  for(j=0;j<N-1;j++)
    {
      printf("%d ",A[j]);
    }
 printf("%d\n",A[j]);
  printf("%d\n",count);
  return 0;
}
