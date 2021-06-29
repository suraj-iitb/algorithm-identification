#include<stdio.h>
int main()
{
  int i,j,mini,N,k,A[100],count=0;

  scanf("%d",&N);
  for(i = 0; i < N; i++) scanf("%d",&A[i]);
  
  for(i = 0; i < N-1; i++)
    {
      mini = i;
      for(j = i; j < N; j++)
	{
	  if(A[j] < A[mini]) mini = j;
	}
      if(i == mini) continue;
      k = A[i];
      A[i] = A[mini];
      A[mini] = k;
      count++; 
    }
  
  for(i = 0; i < N; i ++)
    {
      if(i == N-1)
	{
	  printf("%d",A[i]);
	  break;
	}
      printf("%d ",A[i]);
    }
  printf("\n%d\n",count);
  return 0;
}
