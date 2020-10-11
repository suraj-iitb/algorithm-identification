// Merge Sort
#include <stdio.h>
#include <stdlib.h>
#define SENTINEL 1000000000

void merge(int *a, int left, int mid, int right);
void mergeSort(int *a, int left, int right);

int cnt = 0;

int main() {
  int i, n;
  int *a;
  int left, right, mid;

  // input the length
  scanf("%d", &n);
  // memory allocation
  a = (int *)malloc(n * sizeof(int));
  // input the number
  for(i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  left = 0;
  right = n;
  mid = (left + right) / 2;

  //merge sort
  mergeSort(a, left, right);

  // output
  for(i = 0; i < n; i++) {
    printf("%d", a[i]);
    if(i == n - 1) printf("\n");
    else printf(" ");
  }
  printf("%d\n", cnt);
  
  return 0;
}

void merge(int *a, int left, int mid, int right) {
  int n1, n2;
  int i, j, k;
  int *l, *r;

  n1 = mid - left;
  n2 = right - mid;
  // create array L and R
  l = (int *)malloc((n1+1)*sizeof(int));
  r = (int *)malloc((n2+1)*sizeof(int));
  for(i = 0; i < n1; i++) {
    l[i] = a[left + i];
  }
  for(i = 0; i < n2; i++) {
    r[i] = a[mid + i];
  }
  l[n1] = SENTINEL;
  r[n2] = SENTINEL;
  i = 0;
  j = 0;
  for(k = left; k < right; k++) {
    if(l[i] <= r[j]) {
      a[k] = l[i];
      i = i + 1;
    }
    else {
      a[k] = r[j];
      j = j + 1;
    }
    cnt++;
  }
}

void mergeSort(int *a, int left, int right) {
  int mid;
  
  if(left + 1 < right) {
    mid = (left + right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

