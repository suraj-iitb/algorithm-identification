#include<stdio.h>

int main()
{
  int N,i,j,flag,x,k = 0,A[100];

  scanf("%d",&N);

  for(i = 0;i < N;i++)
    scanf("%d",&A[i]);

  flag = 1;
  i = 0;

  while(flag)
    {
      flag = 0;
      for(j = N - 1;j >= i + 1;j--)
	{
	  if(A[j] < A[j - 1])
	    {
	      x = A[j];
	      A[j] = A[j - 1];
	      A[j - 1] = x;
	      flag = 1;
	      k++;
	    }
	}
      i++;
    }

  for(j = 0;j < N - 1;j++)
    {
      printf("%d ",A[j]);
    }
  printf("%d",A[N - 1]);
  printf("\n");
  printf("%d\n",k);

  return 0;
}
	  

