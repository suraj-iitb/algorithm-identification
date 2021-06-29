#include <stdio.h>

int bubbleSort(int *, int);

int main()
{
  int A[100];
  int N, i, count;

  scanf("%d",&N);
  for(i=0; i<N; i++) scanf("%d",&A[i]);

  count=bubbleSort(A,N);

  for(i=0; i<N; i++)
  {
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");

  printf("%d\n",count);

  return 0;
}

int bubbleSort(int *A, int N)
{
  int i, j, temp;
  int count=0;

  for(i=0; i<N-1; i++)
  {
    for(j=N-1; j>i; j--)
    {
      if(A[j]<A[j-1])
      {
        temp=A[j];
        A[j]=A[j-1];
        A[j-1]=temp;
        count++;
      }
    }
  }
  return count;
}

