#include<stdio.h>
 
int main(void)
{
  int N, i, j, k, v;
  scanf("%d",&N);
  int A[N];
  for(i = 0; i < N ;i++)
  {
    scanf("%d",&A[i]);
    printf("%d",A[i]);
    if (i < N-1)
    {
      printf(" ");
    }
    else
    {
      printf("\n");
    }
  }
  for(i = 1; i < N; i++)
  {
    v = A[i];
    j = i - 1;
    while(j  > -1 && A[j] > v)
    {
      A[j + 1] = A[j];
      j--;
      A[j + 1] = v;
    }
    for(k = 0; k < N; k++)
    {
      if(k > 0)
      {
        printf(" ");
      }
      printf("%d",A[k]);
    }
    printf("\n");
  }
  return 0;
}
