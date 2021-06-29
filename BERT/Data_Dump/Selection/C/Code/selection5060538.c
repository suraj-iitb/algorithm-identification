#include <stdio.h>
#include <stdlib.h>

int selectionSort(int [], int);

int main()
{
  int N,i,s;
  int *A;

  scanf("%d",&N);
  if(!(N>=1 && N<=100)) exit(1);

  A = (int *)malloc(N*sizeof(int));

  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
      if(!(A[i]>=0 && A[i]<=100))
        {
          free(A);
          exit(2);
        }
    }

  s = selectionSort(A,N);

  for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[i]);

  printf("%d\n",s);

  free(A);
  return 0;
}

int selectionSort(int A[], int N)
{
  int tmp,i,j,minj,s=0;

  for(i=0;i<N;i++)
    {
      minj = i;
      for(j=i;j<N;j++)
        {
          if(A[minj] > A[j]) minj = j;
        }
      tmp = A[minj];
      A[minj] = A[i];
      A[i] = tmp;
      if(!(minj==i)) s++;
    }
  return s;
}

