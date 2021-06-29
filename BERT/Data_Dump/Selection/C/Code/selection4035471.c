#include<stdio.h>

int main()
{

  int N,A[100],i,j,minj,a,c=0;
  
  scanf("%d",&N);

  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
    }
  
  for(i=0; i < N; i++)
    {
      minj = i;
      
      for(j=i; j < N; j++)
	{
	  if(A[j] < A[minj]) minj = j;
	}

      if(A[i] > A[minj]){
	a = A[i];
	A[i] = A[minj];
	A[minj] = a;
	c++;
      }
    }

  for(i=0; i < N; i++)
    {
      printf("%d",A[i]);
      if(i < N-1)printf(" ");
    }

  printf("\n%d\n",c);
  
  return 0;
}

