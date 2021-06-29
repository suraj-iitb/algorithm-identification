#include <stdio.h>
int main()
{
  int A[1000];
  int N,i,j,l,v;
  scanf("%d",&N);
  for(i = 0; i < N; i++)scanf("%d",&A[i]);
  for(i = 0; i < N; i++)
  {
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v)
    {
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(l = 0; l < N; l++)
    {
      if(l>0) printf(" ");
      printf("%d",A[l]);
    }
    printf("\n");
  }
  return 0;
}
