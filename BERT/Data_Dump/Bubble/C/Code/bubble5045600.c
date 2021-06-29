#include <stdio.h>

int main()
{
  int a, i, j, k, l, N;
  int count=0;

  scanf("%d",&N);
  int A[N];

  for(i=0; i<N; i++)
  {
    scanf("%d",&A[i]);
  }

  for(j=0; j<N; j++)
  {
    for(k=N-1; k>j; k--)
    {
      if(A[k] < A[k-1])
      {
        a = A[k];
        A[k] = A[k-1];
        A[k-1] = a;
        count++;
      }
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
