#include<stdio.h>

int main()
{
  int N,i,j,k = 0,minj,x,A[100];

  scanf("%d",&N);

  for(i = 0;i < N;i++)
    scanf("%d",&A[i]);

  for(i = 0;i <= N - 1;i++)
    {
      minj = i;
      for(j = i;j <= N - 1;j++)
	{
	  if(A[j] < A[minj])
	    minj = j;

	}
      if(A[i] != A[minj])
	k++;
      
      x = A[i];
      A[i] = A[minj];
      A[minj] = x;
    }
  for(i = 0;i < N - 1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d",A[N - 1]);
  printf("\n");
  printf("%d\n",k);

  return 0;
}

