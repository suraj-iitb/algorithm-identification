#include <stdio.h>

#define N 524288 // 2^19
#define HALFN 262144 // 2^18
#define INFTY 1000000001 // 10^9 + 1

int count = 0, L[HALFN] = {0}, R[HALFN] = {0};

void merge(int *A, int left, int mid, int right) {
  int i, j, k, n1, n2;
  
  n1 = mid - left;
  n2 = right - mid;

  // L[0...n1], R[0...n2] を生成
  for (i = 0; i < n1; i++)
    L[i] = A[left + i];
  for (i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = INFTY;
  R[n2] = INFTY;

  for (i = 0, j = 0, k = left; k < right; k++) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
    count++;
  }
}

void mergeSort(int *A, int left, int right) {
  int mid;
  
  if ((left + 1) < right) {
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(void){
  int i, n, S[N] = {0};
  
  scanf("%d", &n);
  for (i = 0; i < n; i++)
    scanf("%d", &S[i]);

  mergeSort(S, 0, n);
  for (i = 0; i < n; i++) {
    if(i)
      printf(" ");
    printf("%d", S[i]);
  }
  printf("\n%d\n", count);

  return 0;
}
