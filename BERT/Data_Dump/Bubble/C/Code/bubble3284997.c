#include <stdio.h>

void bubbleSort(int[],int);

int main()
{
  int i,N,A[100];

  scanf("%d",&N);
  for(i = 0;i < N;i++)
    {
      scanf("%d",&A[i]);
    }
  bubbleSort(A,N);
  return 0;
}
void bubbleSort(int A[],int N)
{
  int a,i = 0,j,flag = 1,count = 0;
  while(flag == 1)
    {
      flag = 0;
      for(j = N-1;j >= 1;j--)
	{
	  if(A[j] < A[j-1])
	    {
	      a = A[j];
	      A[j] = A[j-1];
	      A[j-1] = a;
	      flag = 1;
	      count++;
	    }
	 
	}
    }
  for(i = 0;i < N;i++)
    {
      if(i > 0) printf(" ");
      printf("%d",A[i]);
    }
  printf("\n%d\n",count);
  
}
  

