#include <stdio.h>

int sum = 0;

void merge(int a[], int left, int mid, int right){
  int n1, n2;
  int l[500000], r[500000];
  int i, j, k, count;

  n1 = mid - left;
  n2 = right - mid;

  for (i = 0; i < n1; i++) {
    l[i] = a[left + i];
  }
  for (i = 0; i < n2; i++) {
    r[i] = a[mid + i];
  }
  l[n1] = 1000000000;
  r[n2] = 1000000000;
  i = 0;
  j = 0;
  for (k = left; k <= right - 1; k++) {
    sum++;
    if (l[i] <= r[j]) {
      a[k] = l[i];
      i = i + 1;
    }
    else {
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

int main(void){
  int n, s[500000];
  int i;

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }

  mergeSort(s, 0, n);

  for (i = 0; i < n; i++) {
    if (i <= n - 2) {
      printf("%d ", s[i]);
    }
    else if (i == n - 1) {
      printf("%d\n", s[i]);
    }
  }
  printf("%d\n", sum);

  return 0;
}


