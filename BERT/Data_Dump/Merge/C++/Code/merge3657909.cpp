#include <climits>
#include <cstdio>
long c;

void merge(int A[], int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1];
  for (int i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    c++;
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else {
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int left, int right) {
  // printf("left:%d, right:%d\n", left, right);
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }
  mergeSort(A, 0, n);

  printf("%d", A[0]);
  for (int i = 1; i < n; i++) {
    printf(" %d", A[i]);
  }
  printf("\n");

  printf("%ld\n", c);
}
