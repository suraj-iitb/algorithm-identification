#include<stdio.h>

int main()
{
  int N,i,A[100],c=0;
  int j,X;
  int minj;


  scanf("%d",&N);

  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
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

      if(minj>i)
	{
	  X=A[i];
	  A[i]=A[minj];
	  A[minj]=X;
	  c++;
	}
    }
 



  for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }

  printf("%d\n",A[N-1]);
  printf("%d\n",c);
  return 0;

}
  
