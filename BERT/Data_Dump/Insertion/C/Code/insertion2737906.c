// ALDS1_1_A:   Insertion Sort
// 2018.3.14

#include <stdio.h>

int
main (void)
{
  int N;
  int A[100] = {};
  int i, j, v, k;

  scanf ("%d\n", &N);
  scanf ("%d", &A[0]);

  for(i = 1; i < N; i++)
    {
        scanf (" %d", &A[i]);
    }
  // 1st line
  
  printf ("%d", A[0]);
  
  for (k = 1; k < N; k++)
    {
      printf (" %d", A[k]);
    }
  printf ("\n");
      
  //insertionSort(A, N) // N個の要素を含む0-オリジンの配列A

  for(i = 1; i < N; i++)
    {
      v = A[i];
      j = i - 1;
      while (j >= 0 && A[j] > v)
	{
	  A[j+1] = A[j];
	  j--;
	}
      A[j+1] = v;

  // lest lines
      
      printf ("%d", A[0]);
      
      for (k = 1; k < N; k++)
	{
	  printf (" %d", A[k]);
	}
      printf ("\n");
    }
  return 0;
}
