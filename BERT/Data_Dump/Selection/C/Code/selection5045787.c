#include <stdio.h>

int main()
{
  int a, b, i, j, k, l, N, minj;
  int count = 0;

  scanf("%d",&N);
  int A[N];

  for(i=0; i<N; i++)
  {
    scanf("%d",&A[i]);
  }

  for(j=0; j<N; j++)
  {
    a = j;

    for(k=j+1; k<N; k++)
    {
      if(A[k] < A[a]) a = k;
    }

    if(A[j] > A[a])
    {
      b = A[j];
      A[j] = A[a];
      A[a] = b;
      count++;
    }
  }

  for(l=0; l<N; l++)
  {
    printf("%d",A[l]);
    if(l<N-1) printf(" ");
  }

  printf("\n");
  printf("%d\n",count);

  return 0;
}
