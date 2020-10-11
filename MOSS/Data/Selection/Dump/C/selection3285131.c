#include <stdio.h>

void selectionSort(int[],int);

int main()
{
  int i,N,A[100];

  scanf("%d",&N);
  for(i = 0;i < N;i++)
    {
      scanf("%d",&A[i]);
    }
  selectionSort(A,N);
  return 0;
}
void selectionSort(int A[],int N)
{
  int a,i,j,minj,count = 0;
  for(i = 0;i <= N-1;i++)
    {
      minj = i;
      for(j = i;j <= N-1;j++)
	{
	  if(A[j] < A[minj])
	    {
	      minj = j;
	    }
	}
      a = A[i];
	      A[i] = A[minj];
	      A[minj] = a;
	      if(i != minj) count++;
    }
  for(i = 0;i < N;i++)
    {
      if(i > 0) printf(" ");
      printf("%d",A[i]);
    }
  printf("\n%d\n",count);
  
}

