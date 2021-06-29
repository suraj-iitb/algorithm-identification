#include <stdio.h>

int main()
{
  int a=0,i,j,k,sc=0,N,A[100];

  scanf("%d",&N);
  
  for(i=0; i < N ; i++)
  {
    scanf(" %d",&A[i]);
    if(A[i] < 0 || A[i] > 100)
      {
	printf("This number can't be accepted");
	a++;
      }
  }

  if(a == 0)
    {
      for(i = 0; i < N; i++ )
      
      for(i=1; i < N ; i++)
	{
	  for(j=N-1 ; j >= i ; j--)
	    {
	      if(A[j] < A[j-1])
		{
		  k=A[j];
		  A[j] = A[j-1];
		  A[j-1] = k;
		  sc++;
		}
	    }
	}
      for(i=0 ; i < N ; i++)
	{
	  printf("%d",A[i]);
	  if(i != N-1)
	    {
	      printf(" ");
	    }
	  else printf("\n");
	}
      
      printf("%d\n",sc);
    }
 
}

