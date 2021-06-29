#include <stdio.h>

void insertionSort(int A[],int N) // N個の要素を含む0-オリジンの配列A
{
  int i,j,v,u;
  for(i= 1; i<N; i++)
  {
    v = A[i];
    j = i-1;

    while(j >= 0 && A[j] > v)
    {
      A[j+1] = A[j];
      j--;
    }

    A[j+1]=v;
    for(u = 0; u < N; u++)
    {
      if(u>0) printf(" ");
      printf("%d",A[u]);
    }
    printf("\n");
  }

}

int main()
{
  int i,N,a[100];

  scanf("%d",&N);
  for(i=0; i<N; i++) scanf("%d",&a[i]);

  for(i = 0; i < N; i++)
  {
    if(i>0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");

  insertionSort(a,N);
  return 0;
}

