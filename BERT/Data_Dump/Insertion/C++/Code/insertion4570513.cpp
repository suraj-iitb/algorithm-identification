#include <bits/stdc++.h>
using namespace std;

void print_array(int *A, int N){
  printf("%d", A[0]);
  for(int i = 1; i < N; ++i)
  {
    printf(" %d", A[i]);
  }
  printf("\n");
}

int main()
{
  int i, j, k, v, N;
  int A[100+5];
  scanf("%d", &N);

  for(i = 0; i < N; ++i)
  {
    scanf("%d", &A[i]);
  }
  print_array(A, N);

  for(i = 1; i < N; ++i)
  {
    v = A[i];
    j = i - 1;
    while(j>=0 && A[j] > v)
    {
      A[j+1] = A[j];
      --j;
    }
    A[j+1] = v;
    print_array(A, N);
  }

  return 0;
}
