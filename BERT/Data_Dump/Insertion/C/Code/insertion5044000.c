#include <stdio.h>

int main()
{
  int i, j, k, v, N;

  scanf("%d",&N);

  int A[N];

  for(k=0; k<N; k++)
  {
    scanf("%d",&A[k]);
  }

  for(i=0; i<N; i++)
  {
    v = A[i];
    j = i-1;

    while(j>=0 && A[j] > v)
    {
      A[j+1] = A[j];
      j--; 
    }

    A[j+1] = v;

    for(k=0; k<N; k++)
    {
      printf("%d",A[k]);
      if(k<N-1) printf(" ");
    }

    printf("\n");
  }

  return 0;
}
