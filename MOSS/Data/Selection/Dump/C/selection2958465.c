#include <stdio.h>
#include <stdlib.h>

int selectionSort(int*,int);

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
  kai = selectionSort(arr,N);
  for(i = 0; i < N; i++)
    {
      if(i) printf(" ");
      printf("%d",arr[i]);  
    }
  printf("\n");
  printf("%d\n",kai);
  
  
  return 0; 
} 

int selectionSort(int* A,int N)
{
  int i;
  int j;
  int count=0;
  int minj;
  int temp;
  
  for (i = 0; i < N; i++)
    {
      minj = i;
      for(j = i; j < N; j++)
	{
	  if(A[j] < A[minj])
	    minj = j;
	}
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      if(i != minj) count++;
    }
  return count;
}

