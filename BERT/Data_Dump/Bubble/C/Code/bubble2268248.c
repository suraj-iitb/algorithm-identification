#include <stdio.h>

int main()
{
  int N;
  int A[100];
  int i, j, tmp, counter = 0;

  scanf("%d", &N);
  for(i = 0; i < N; i++)
    {
      scanf("%d", &A[i]);
    }
  for(i = 0; i < N-1; i++)
    {
      for(j = N-1; j >= i+1; j--)
	{
	  if(A[j] < A[j-1])
	    {
	      tmp = A[j];
	      A[j] = A[j-1];
	      A[j-1] = tmp;
	      counter++;
	    }
	}
    }
  for(i = 0; i < N; i++)
    {
      printf("%d", A[i]);
      if(i != N-1) printf(" ");
    }
  printf("\n");
  printf("%d\n", counter);
  
  return 0;
}
