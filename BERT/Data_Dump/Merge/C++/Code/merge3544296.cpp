#include <stdio.h>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int cnt;

void merge(int A[], int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2];
  for (int i = 0; i < n1; i++)
  {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++)
  {
    R[i] = A[mid + i];
  }
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  int i = 0, j = 0;
  for (int k = left; k < right; k++)
  {
    if (L[i] <= R[j])
    {
      A[k] = L[i];
      i = i + 1;
    }
    else
    {
      A[k] = R[j];
      j = j + 1;
    }
    cnt++;
  }
}

void mergeSort(int A[], int left, int right)
{
  if (left + 1 < right)
  {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main()
{
  int n;
  int s[MAX];

  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &s[i]);
  }

  mergeSort(s, 0, n);

  for (int i = 0; i < n - 1; i++)
  {
    printf("%d ", s[i]);
  }
  printf("%d\n", s[n - 1]);
  printf("%d\n", cnt);
  return 0;
}
