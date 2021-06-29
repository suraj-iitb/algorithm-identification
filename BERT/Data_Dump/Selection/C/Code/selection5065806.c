#include<stdio.h>

int selectionSort(int A[], int N)
{
    int i,j,minj,B[2];
    int count = 0;
    int k;

    for(i=0; i< N; i++)
    {
      minj = i;
      for(j=i; j<N; j++)
      {
        if(A[j] < A[minj])
        {
          minj=j;
          k=1;
        }
      }

      count += k;
      B[0] = A[i];
      B[1] = A[minj];
      A[i] = B[1];
      A[minj] = B[0];
      k = 0;
    }
    return count;
}

int main()
{
  int i,count,N,A[100];

  scanf("%d",&N);
  for(i=0; i<N; i++) scanf("%d",&A[i]);

  count = selectionSort(A, N);

  for(i=0; i<N; i++)
  {
    printf("%d",A[i]);
    if(i < N-1) printf(" ");
  }

  printf("\n%d\n",count);

  return 0;
}
