#include <stdio.h>

int main()
{
  int A[100],N,chan=0,i,j,minj=0,count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  for (i = 0; i< N-1;i++)
    {
      minj = i;
      for (j = i+1; j<N;j++)
	{	  
	  if (A[j] < A[minj])  minj = j;
	    
	}
      chan=A[i];
      A[i]=A[minj];
      A[minj]=chan;
      if(minj!=i)count++;	    
    }


	    
  for(i=0;i<N;i++)
    {
      printf("%d",A[i]);
      if(i!=N-1)printf(" ");
    }
  printf("\n%d\n",count);

  return 0;
  
}

