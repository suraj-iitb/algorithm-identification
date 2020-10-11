#include <stdio.h>
#include <stdlib.h>
int main(){
  int frag =1;
  int N,j,count=0,tmp;
  int *A;
  scanf("%d",&N);
  if(N<1 || N>100) exit(1);
  A = (int *)malloc(N*sizeof(int));
  for(j=0;j<N;j++)
    {
      scanf("%d",&A[j]);
      if(A[j]<0 || A[j]>100) exit(1);
    }
  while(frag == 1)
    {
      frag = 0;
      for(j=N-1;j>0;j--)
	{
	  if(A[j]<A[j-1])
	    {
	      tmp = A[j];
	      A[j] = A[j-1];
	      A[j-1] = tmp;
	      frag =1;
	      count++;
	    }
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
  
  

