#include<stdio.h>
#define MAX 2000000

void CountingSort(int [], int [], int, int);

int main()
{
  int A[MAX], B[MAX], n, i, k = 0;

  scanf("%d", &n);

  for(i = 1; i < n + 1; i++){
    scanf("%d", &A[i]);
    if(A[i] > k)
      k = A[i];
  }

  CountingSort(A, B, n, k);

  return 0;
}

void CountingSort(int A[], int B[], int n, int k)
{
  int i, j, C[k + 1];

  for(i = 0; i < k + 1; i++)
    C[i] = 0;

  for(j = 1; j < n + 1; j++)
    C[A[j]]++;

  for(i = 1; i < k + 1; i++)
    C[i] = C[i] + C[i - 1];

  for(j = n; j >= 1; j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }

  for(i = 1; i < n + 1; i++){
    if(i == n)
      printf("%d\n", B[i]);
    else
      printf("%d ", B[i]);
  }
}

