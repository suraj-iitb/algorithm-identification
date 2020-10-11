#include <stdio.h>
#include <stdlib.h>

#define SENTINEL (1<<30)

int Merge(int *A, int left, int mid, int right) {
  int cnt = 0;
  int i,j,k;
  int n1, n2;
  int *L, *R;
  n1 = mid - left;
  n2 = right - mid;
  L = malloc(sizeof(int)*(n1+1));
  R = malloc(sizeof(int)*(n2+1));
  for(i = 0; i < n1; ++i)
    L[i] = A[left+i];
  for(i = 0; i < n2; ++i)
    R[i] = A[mid+i];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  i = 0;
  j = 0;
  for(k = left; k < right; ++k) {
    ++cnt;
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i = i + 1;
    } else {
      A[k] = R[j];
      j = j + 1;
    }
  }
  free(L);
  free(R);
  return cnt;
}

int Merge_Sort(int *A, int left, int right) {
  int cnt = 0;
  int mid;
  if(left+1 < right) {
    mid = (left + right)/2;
    cnt += Merge_Sort(A, left, mid);
    cnt += Merge_Sort(A, mid, right);
    cnt += Merge(A, left, mid, right);
  }
  return cnt;
}

int main() {
  int i;
  int n, A[500000], cnt;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf("%d", A+i);
  }
  cnt = Merge_Sort(A,0,n);
  for(i = 0; i < n; ++i) {
    printf(i ? " %d" : "%d", A[i]);
  }
  printf("\n%d\n", cnt);
  return 0;
}
