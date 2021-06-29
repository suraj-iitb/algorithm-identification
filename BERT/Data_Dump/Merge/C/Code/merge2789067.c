#include <stdio.h>
#include <limits.h>

int comparisons = 0;

void merge(int A[], int left, int mid, int right) {
  int n1, n2, i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1], R[n2+1];

  for (i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for (i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }

  L[n1] = R[n2] = INT_MAX;
  i = 0, j = 0;

  for (k = left; k < right; k++) {
    comparisons++;
    if (L[i] <= R[j])
      A[k] = L[i++];
    else
      A[k] = R[j++];
  }
}

void mergeSort(int A[], int left, int right) {
  if (left + 1 < right) {
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int n, i;

  scanf("%d", &n);

  int arr[n+5];
  
  for (i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  mergeSort(arr, 0, n);

  for (i = 0; i < n; i++) {
    if (i == n - 1)
      printf("%d\n", arr[i]);
    else
      printf("%d ", arr[i]);
  }
  printf("%d\n", comparisons);
}


