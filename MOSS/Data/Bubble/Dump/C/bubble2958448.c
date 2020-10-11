#include <stdio.h>
#include <stdlib.h>

int bublleSort(int*,int);

int main()
{
  int N;
  int i;
  int arr[100];
  int kai;
  
  scanf("%d",&N);
  if(N < 1 || N > 100) exit(1);
  for(i = 0; i < N; i++)
    {
      scanf("%d",&arr[i]);
      if(arr[i] < 0 || arr[i] > 100) exit(1);
    }
  kai = bublleSort(arr,N);

  for(i = 0; i < N; i++)
    {
      if(i) printf(" ");
      printf("%d",arr[i]);  
    }
  printf("\n");
  printf("%d\n",kai);
  
  return 0;
}

int bublleSort(int* A,int N)
{
  int flag = 1;
  int j;
  int count=0;
  int temp;
  
  while(flag)
    {
      flag = 0;
      for(j = N - 1; j >= 1; j--)
	{
	  if(A[j] < A[j-1])
	    {
	      temp = A[j];
	      A[j] = A[j-1];
	      A[j - 1] = temp;
	      count++;
	      flag = 1;
	    }
	}
    }
  
  return count;
}

