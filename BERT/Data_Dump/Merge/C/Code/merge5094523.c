#include <stdio.h>
#include <math.h>
#define MAX 500000

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int count;
int L[MAX], R[MAX];

int main()
{
  int i, n;
  int S[MAX];

  scanf("%d", &n);
  for (i=0; i<n; i++) {
    scanf("%d", &S[i]);
  }
  int left = 0;
  int right = n;

  mergeSort(S, left, right);

  for (i=0; i<=n-1; i++) {
    if (i==n-1) printf("%d", S[i]);
    else printf("%d ", S[i]);
  }
  printf("\n%d\n", count);

  return 0;
}

void merge(int S[], int left, int mid, int right)
{
  int n1, n2;
  int i, j, k;

  n1 = mid - left;
  n2 = right - mid;
  //L[0...n1], R[0...n2] を生成
  for (i = 0; i <= n1-1; i++)
    L[i] = S[left + i];
  for (i = 0; i <= n2-1; i++)
    R[i] = S[mid + i];
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for (k = left; k <= right-1; k++) {
    count++;
    if (L[i] <= R[j]) {
      S[k] = L[i];
      i = i + 1;
    } else {
      S[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int S[], int left, int right)
{
  if (left+1 < right) {
    int mid = (left + right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}

