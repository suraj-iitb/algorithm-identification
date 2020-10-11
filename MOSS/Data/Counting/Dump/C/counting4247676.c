#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

void CountingSort(short[],short[],int);

int main()
{
  unsigned short*A, *B;
  int C[MAX];
  int n;
  int i,j;

  scanf("%d", &n);

  A = malloc(sizeof(short) * (n + 1));
  B = malloc(sizeof(short) * (n + 1));

  for (i = 1; i < n + 1; i++)
    scanf("%hu", &A[i]);

  CountingSort(A,B,n);

  for (i = 1; i < n + 1; i++)
  {
    if (i > 1)
      printf(" ");

    printf("%d", B[i]);
  }

  printf("\n");

  free(A);
  free(B);

  return 0;
}

void CountingSort(short A[],short B[],int n)
{
  int i, j;
  int C[MAX];

  for (i = 0; i < MAX; i++)
    C[i] = 0;

  for (j = 1; j < n + 1; j++)
    C[A[j]]++;

  for (i = 1; i < MAX; i++)
    C[i] = C[i] + C[i - 1];

  for (j = n; j >= 1; j--)
  {
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
} 
