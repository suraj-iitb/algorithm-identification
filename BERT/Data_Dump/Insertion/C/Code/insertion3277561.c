#include <stdio.h>
#include <stdlib.h>

void pri(int[], int);
int main()
{
  int i,v,j,N = 0,A[100];
  scanf("%d",&N);
  for(i = 0;i < N;i++)
    {
      scanf("%d",&A[i]);
      //if(A[i] >= 1000 || A[i] <= 0) i--;
    }
  pri(A,N);
  for(i = 1;i < N;i++)
    {
      
      v = A[i];
      j = i - 1;

      while(j >= 0 && A[j] > v)
	{
	  A[j+1] = A[j];
	  j--;
	  
	}
      A[j+1] = v;
      pri(A,N);
    }
	
      
      
  return 0;
}
void pri(int A[],int N)
{
  int i;
  for(i = 0;i < N;i++)
    {
      if(i > 0) printf(" ");
      printf("%d",A[i]);
    }
  printf("\n");
}

