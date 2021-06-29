#include <stdio.h>

int selectionSort(int *, int);

int main()
{
  int A[100];
  int N, i, count;

  scanf("%d",&N);
  for(i=0; i<N; i++) scanf("%d",&A[i]);

  count=selectionSort(A, N);

  for(i=0; i<N; i++)
  {
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);

  return 0;
}

int selectionSort(int *A, int N)
{
  int i, j, minj, temp, count=0;

  for(i=0; i<N-1; i++)
  {
    minj=i;
    for(j=i+1; j<N; j++)
    {
      if(A[j]<A[minj]) minj=j;
    }
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      if(i!=minj) count++;
  }
  return count;
}

