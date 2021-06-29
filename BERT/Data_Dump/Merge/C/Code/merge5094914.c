#include <stdio.h>
#define MAX 500000
#define INFTY 2000000000

void mergesort(int *, int, int);
void merge(int *, int, int, int);

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int count;
int S[MAX];

int main()
{
  int n, i;
  count = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    scanf("%d", &S[i]);
  }

  mergesort(S, 0, n);

  for (i = 0; i < n; i++)
  {
    printf("%d", S[i]);
    if (i == n - 1)
      printf("\n");
    else
      printf(" ");
  }
  printf("%d\n", count);
  return 0;
}

void mergesort(int A[], int left, int right)
{
  int mid;
  if (left + 1 < right)
  {
    mid = (left + right) / 2;
    mergesort(A, left, mid);
    mergesort(A, mid, right);
    merge(A, left, mid, right);
  }
}

void merge(int A[], int left, int mid, int right)
{
  int i, j, k, n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left; k < right; k++)
  {
    count++;
    if (L[i] <= R[j])
      A[k] = L[i++];
    else
      A[k] = R[j++];
  }
}

