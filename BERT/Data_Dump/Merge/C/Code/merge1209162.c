#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int ct;

void mergeSort(int *A, int left, int right);
void merge(int *A, int left, int mid, int right);

int main(int argc, char *argv[])
{
  int n, i;
  int *S;

  ct = 0;

  scanf("%d", &n);
  S = (int *)malloc(sizeof(int) * n);
  for (i = 0; i < n; i++) scanf("%d", &S[i]);

  mergeSort(S, 0, n);

  for (i = 0; i < n; i++) {
    if (i != n - 1) printf("%d ", S[i]);
    else printf("%d\n", S[i]);
  }
  printf("%d\n", ct);

  return 0;
}

void mergeSort(int *A, int left, int right)
{
  int mid;

  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

void merge(int *A, int left, int mid, int right)
{
  int n1 = mid - left, n2 = right - mid;
  int *L, *R;
  int i, j, k;

  L = (int *)malloc(sizeof(int) * (n1 + 1));
  R = (int *)malloc(sizeof(int) * (n2 + 1));

  for (i = 0; i < n1; i++) L[i] = A[left+i];
  for (i = 0; i < n2; i++) R[i] = A[mid+i];

  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i = 0;
  j = 0;

  for (k = left; k < right; k++) {
    ct++;
    if (L[i] <= R[j]) A[k] = L[i++];
    else A[k] = R[j++];
  }
}
