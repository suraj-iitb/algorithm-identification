#include <stdio.h>
#include <stdlib.h>


int main()
{
  int N,i,j,v,count=0,minj;
  int *A;

  scanf("%d",&N);
  if(N<1 || N>100) exit(2);
  A=(int *)malloc(sizeof(int)*N);

  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
      if(A[i]<0 || A[i]>100) exit(1);
    }

  for(i=0;i<N;i++)
    {
      minj=i;
      for(j=i;j<N;j++)
	{
	  if(A[j]<A[minj])
	    {
	      minj=j;  
	    }
	}

      
      v=A[i];
      A[i]=A[minj];
      A[minj]=v;
      if(A[i]!=A[minj]) count++;
      
    }

  for(i=0;i<N-1;i++)
	{
	  printf("%d ",A[i]);
	  
	}
  printf("%d",A[N-1]);
  printf("\n");

  printf("%d\n",count);



  return 0;
}

