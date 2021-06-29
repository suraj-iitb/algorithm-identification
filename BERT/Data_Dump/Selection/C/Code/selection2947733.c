#include <stdio.h>
#include <stdlib.h>
int main() {
  int i,j,N,minj,tmp,count=0;
  int *A;
  scanf("%d",&N);
  if(N<1 || N>100) exit(1);
  A = (int *)malloc(N*sizeof(int));
  for(j=0;j<N;j++)
    {
      scanf("%d",&A[j]);
      if(A[j]<0 || A[j]>100) exit(1);
    }
  for(i=0;i<N;i++)
    {
      minj = i;
      for(j=i;j<N;j++)
	{
	  if(A[j]<A[minj])
	    {
	      minj = j;
	    }
	}
      if(A[minj]<A[i])
	{
	  tmp = A[i];
	  A[i] = A[minj];
	  A[minj] = tmp;
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

