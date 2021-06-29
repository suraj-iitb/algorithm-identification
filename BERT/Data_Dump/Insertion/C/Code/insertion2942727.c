#include <stdio.h>
#include <stdlib.h>
int main() {
  int i,j,v;
  int N;
  int *A;
  scanf("%d",&N);
  if(N<1 || N>100) exit(8);
  A = (int*)malloc(N*sizeof(int));
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
      if(A[i]<0 || A[i]>1000) exit(8);
    }
  for(j=0;j<N-1;j++)
    {
      printf("%d ",A[j]);
    }
  printf("%d\n",A[j]);
  for(i=1;i<=N-1;i++)
    {      
      v=A[i];
      j = i-1;
      while(j>=0 && A[j]>v)
	{
	  A[j+1] = A[j];
	  j--;
	  A[j+1] = v;
	}
      for(j=0;j<N-1;j++)
	{
	  printf("%d ",A[j]);
	}
      printf("%d\n",A[j]);
    }
  free(A);
  return 0;
}

