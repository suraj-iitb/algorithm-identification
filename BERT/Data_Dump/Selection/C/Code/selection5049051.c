#include <stdio.h>

int main()
{
  int con=0,min,minj,i,j,N,A[100];

  scanf("%d",&N);

  for(i=0 ; i < N ; i++)
    {
      scanf("%d",&A[i]);
    }


  for(i=0 ; i < N-1 ; i++)
    {
      minj = i;
      for(j=i ; j < N ; j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj = j;
	    }
	}
      if(minj != i)
	{
	  min = A[minj];
	  A[minj] = A[i];
	  A[i] = min;
	  con++;
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

  printf("%d\n",con);

  return 0;
}

