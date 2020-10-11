#include <stdio.h>

int main()
{
  int v,i,j,N;
  int A[1000];

  scanf("%d",&N);

  if(N < 1 || N > 100) return 0;

  for( i = 0 ; i < N ; i++ )
    {
      scanf("%d",&A[i]);
    }
  
  for( j = 0 ; j < N ; j++ )
    {
      if(j == N-1) printf("%d",A[j]);
      else printf("%d ",A[j]);
    }
  printf("\n");

  for( i = 1 ; i <= N-1 ; i++ )
    {
      v = A[i];
      j = i - 1;

      while(j >= 0 && A[j] > v)
	{
	  A[j+1] = A[j];
	  j--;
	}
      A[j+1] = v;

      for( j = 0 ; j < N ; j++ )
	{
	  if(j == N-1) printf("%d",A[j]);
	  else printf("%d ",A[j]);
	}
      printf("\n");
    }

  
  return 0;
}

