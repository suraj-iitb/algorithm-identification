#include <stdio.h>
#include <stdlib.h>

int bubbleSort(int [],int );

int main()
{
  int N,i,b;
  int *A;

  scanf("%d",&N);
  if(!(N>=1 && N<=100)) exit(1);

  A =(int *)malloc(N*sizeof(int));
  for(i=0;i<N;i++)
    {
      scanf("%d",&A[i]);
      if(!(A[i]>=0 && A[i]<=100))
        {
          free(A);
          exit(2);
        }
    }

  b = bubbleSort(A,N);

  for(i=0;i<N-1;i++)
    {
      printf("%d ",A[i]);
    }
  printf("%d\n",A[i]);

  printf("%d\n",b);

}

int bubbleSort(int A[], int N)
{
  int flag = 1;
  int i = 0;
  int j,tmp,b = 0;

  while(flag)
    {
      flag = 0;
      for(j = N-1;j>=i+1;j--)
        {
          if(A[j] < A[j-1])
            {
              tmp = A[j];
              A[j] = A[j-1];
              A[j-1] = tmp;
              b++;
              flag = 1;
            }
        }
      i++;
    }
  return b;
}
