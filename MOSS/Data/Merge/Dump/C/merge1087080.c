#include <stdio.h>
#include <stdlib.h>
#define INF 1000000001
#define MAX_N 500000

int cnt = 0;

void merge(int A[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;

  int *L = malloc(sizeof(int)*(n1+1));
  int *R = malloc(sizeof(int)*(n2+1));
  for (i = 0; i < n1; i++) {
    L[i] = A[left+i];
  }
  for (i = 0; i < n2; i++) {
    R[i] = A[mid+i];
  }
  L[n1] = INF;
  R[n2] = INF;

  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    cnt++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }

  free(L);
  free(R);
}

void merge_sort(int A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right)/2;
    merge_sort(A, left, mid);
    merge_sort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(void) {
  int i, n;
  int ary[MAX_N];
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &ary[i]);
  }

  merge_sort(ary, 0, n);
  for (i = 0; i < n-1; i++) {
    printf("%d ", ary[i]);
  }
  printf("%d\n", ary[n-1]);
  printf("%d\n", cnt);
  
  return 0;
}
