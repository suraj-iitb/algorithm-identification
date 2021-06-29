#include<stdio.h>

int main()
{
  int A[100], N, sw, i;

  scanf("%d",&N);
  
  for( i = 1 ; i < N + 1 ; i++ )
    {
      scanf("%d",&A[i]);
    }

  sw = bubbleSort(A, N);
  
  printf("%d\n",sw);
 
  return 0;
}

int bubbleSort(int A[],int N)
{
  int sw = 0, i, j, temp;

  for( i = 1 ; i < N + 1 ; i++ )
    {
      for( j = N ; j > i ; j-- )
	{
	  if(A[j] < A[j - 1])
	    {
	      sw++;
	      temp = A[j];
	      A[j] = A[j - 1];
	      A[j - 1] = temp;
	    }
	}
      if(i > 1)
	{
	  printf(" ");
	}
      printf("%d",A[i]);
    }
  printf("\n");
  
  return sw;
}
