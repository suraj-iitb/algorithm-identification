#include <stdio.h>

#define MAX 500000
#define INFTY 1000000001

void mergeSort(int A[], int, int);
void merge(int A[], int, int, int);

int S[MAX];
int n;
int cnt;

int main(void) {
  int left, right;

  scanf("%d", &n);

  left = 0; right = n;

  for(int i=0; i<n; ++i)
    scanf("%d", &S[i]);

  mergeSort(S, left, right);

  for(int i=0; i<n; ++i) {
    if(i != n-1) printf("%d ", S[i]);
    else printf("%d\n", S[i]);
  }
  printf("%d\n", cnt);

  return 0;
}

void mergeSort(int A[], int left, int right) {
  int mid;

  if(left+1 < right) {
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

void merge(int A[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2];

  for(i=0; i<n1; ++i)
    L[i] = A[left + i];
  for(i=0; i<n2; ++i)
    R[i] = A[mid + i];
  L[n1] = R[n2] = INFTY;
  i = j = 0;
  for(k=left; k<right; ++k) {
    ++cnt;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      ++i;
    }
    else {
      A[k] = R[j];
      ++j;
    }
  }

}

