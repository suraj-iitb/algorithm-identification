#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N,i,v,j,k;
  int *A;

  scanf("%d",&N);
  if(N<1 || N>100) exit(2);
  A=(int *)malloc(sizeof(int)*N);
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
      if(A[i]<0 || A[i]>1000) exit(1);
    }

  for(k=0;k<N-1;k++)
	{
	  printf("%d ",A[k]);
	  
	}
  printf("%d",A[N-1]);
  printf("\n");
  
  for(i=1;i<N;i++)
    {
      v=A[i];
      j=i-1;
      while(j>=0 && A[j]>v)
	{
	  A[j+1]=A[j];
	  j--;
	}
      A[j+1]=v;
      for(k=0;k<N-1;k++)
	{
	  printf("%d ",A[k]);
	}
      printf("%d",A[N-1]);
       printf("\n");
      
    }


  return 0;
}

