#include <stdio.h>
//#define N 100

int main()
{
  int i, j, k,N ,key;
  int A[100];
  
  scanf("%d", &N);
  for(i = 0; i <= N-1; i++)
    {
      scanf("%d", &A[i]);
    }
  for(k = 0; k <= N-1; k++)
	{
	  printf("%d",A[k]);
	  if(k != N-1)
	    {
	      printf(" ");
	    }
	  else
	    printf("\n");
	}
  
  for(i = 1; i <= N - 1; i++)
    {
      key = A[i];
      j = i - 1;
      while(j >= 0 && A[j] > key)
	{
	  A[j+1] = A[j];
	  j--;
	}
      A[j+1] = key;
      for(k = 0; k <= N-1; k++)
	{
	  printf("%d",A[k]);
	  if(k != N-1)
	    {
	      printf(" ");
	    }
	  else
	    printf("\n");
	}
    }
  return 0;
}

