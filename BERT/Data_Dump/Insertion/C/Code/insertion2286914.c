#include <stdio.h>

void printA(int *A, int N);

int main()
{
  int i,j,N,key;
  int A[100];

  scanf("%d", &N);
  for(i=0; i<N; i++)
      scanf("%d", &A[i]);

  printA(A,N);
  for(i=1; i<N; i++)
    {
      key = A[i];
      j = i-1;
      while( j >= 0 && A[j] > key )
	{
	  A[j+1] = A[j];
	  j--;
	}
      A[j+1] = key;
      printA(A,N);
    }
  

  return 0;
}


void printA(int *A, int N)
{
  int i;
  for(i=0; i<N-1; i++)
      printf("%d ", A[i]);
  printf("%d\n", A[N-1]);
}
