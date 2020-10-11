#include <stdio.h>

#define MAX 10000000000

int n, cnt = 0;

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int main() {
  int i, S[500000];
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &S[i]);
  }

  mergeSort(S, 0, n);
  for (i = 0; i < n; i++) {
    if (i == n-1) {
      printf("%d", S[i]);
      break;
    }
    printf("%d ", S[i]);
  }
  printf("\n%d\n", cnt);

  return 0;
}

void merge(int* A,int left, int mid, int right) {
  int n1, n2, i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  int l[n1];
  int r[n2];
  for (i = 0; i < n1; i++) {
    l[i] = A[left+i];
  }
  for (i = 0; i < n2; i++) {
    r[i] = A[mid+i];
  }
  l[n1] = MAX;
  r[n2] = MAX;
  i = j = 0;
  for (k = left; k < right; k++) {
    if (l[i] <= r[j]) {
      A[k] = l[i];
      i++;
      cnt++;
    } else {
      A[k] = r[j];
      j++;
      cnt++;
    }
  }
}

void mergeSort(int* A, int left, int right) {
  if (left+1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
