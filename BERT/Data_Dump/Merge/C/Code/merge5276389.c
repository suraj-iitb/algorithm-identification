#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void print_a(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d", arr[n - 1]);
  printf("\n");
}


int merge(int arr[], int l, int m, int r, int count) {

  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++)
    L[i] = arr[l + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[m + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < n1 && j < n2) {
    count++;
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    }
    else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
    count++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
    count++;
  }
  return count;
}

int merge_sort(int arr[], int l, int r) {
  int count = 0;
  if (l < r) {
    int m = l + (r - l) / 2;

    int x = merge_sort(arr, l, m);
    int y = merge_sort(arr, m + 1, r);
    
    count = count + x + y;

    count = merge(arr, l, m, r, count);
  }
  return count;
}

int main(void) {
  int n;

  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int count = merge_sort(arr, 0, n - 1);
  print_a(arr, n);
  printf("%d\n", count);

  return 0;
}

