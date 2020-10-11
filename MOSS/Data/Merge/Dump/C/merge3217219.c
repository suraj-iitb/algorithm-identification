#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int count = 0;

void merge(int a[], int left, int mid, int right) {
  int i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  int l[mid - left + 1];
  int r[right - mid + 1];
  for (i = 0; i < n1; i++) {
    l[i] = a[left + i];
  }
  for (i = 0; i < n2; i++) {
    r[i] = a[mid + i];
  }

  l[n1] = (int)INFINITY;
  r[n2] = (int)INFINITY;
  i = 0;
  j = 0;
  for (k = left; k < right; k++) {
    count++;
    if (l[i] <= r[j]) {
      a[k] = l[i];
      i = i + 1;
    } else {
      a[k] = r[j];
      j = j + 1;
    }
  }
}

void mergeSort(int a[], int left, int right) {
  int mid;
  if (left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}


int main(void) {
  int i, j, k, n, l;
  int a[1000000] = {0};
  scanf("%d", &l);
  for (i = 0; i < l; i++) {
    scanf("%d", &a[i]);
  }

  mergeSort(a, 0, l);

  for (k = 0; k < l; k++) {
    printf("%d", a[k]);
    if (k < l - 1) {
      printf(" ");
    }
  }
  printf("\n%d\n", count);


  return 0;
}

