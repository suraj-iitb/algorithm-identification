#include <stdio.h>

#define Max 500000

int l[Max / 2 + 1], r[Max / 2 + 1];
int count;

void merge(int a[], int right, int mid, int left, int n) {
  int n1 = mid - left;
  int n2 = right - mid;
  int i, j, k;
  for (i = 0; i < n1; i++) {
    l[i] = a[left + i];
  }
  for (i = 0; i < n2; i++) {
    r[i] = a[mid + i];
  }
  l[n1] = r[n2] = 1000000000;
  i = 0, j = 0;
  for (k = 0; k <  n1 + n2; k++) {
    ++count;
    if (l[i] <= r[j]) {
      a[left + k] = l[i++];
    } else {
      a[left + k] = r[j++];
    }
  }
}

void sort(int a[], int right, int left, int n) {
  if (left < right - 1) {
    int mid = (right + left) / 2;
    sort(a, mid, left, n);
    sort(a, right, mid, n);
    merge(a, right, mid, left, n);
  }
}

int main() {
  int a[Max + 1];
  int n;
  int i;
  count = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a, n, 0, n);
  for (i = 0; i < n; i++) {
    if (i != n - 1) {
      printf("%d ", a[i]);
    } else {
      printf("%d\n", a[i]);
    }
  }
  printf("%d\n", count);

  return 0;
}

