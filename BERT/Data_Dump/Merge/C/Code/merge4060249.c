#include <stdio.h>
#include <stdlib.h>

#define MAX 1000000000

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int count = 0;

int main() {
  int i, n;
  int data[500000];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &data[i]);
  }

  mergeSort(data, 0, n);

  for (i = 0; i < n; i++) {
    printf("%d" ,data[i]);
    if (i != n-1) {
      printf(" ");
    }
    else {
      printf("\n");
    }
  }

  printf("%d\n", count);

  return 0;
}


void merge(int *data, int left, int mid, int right) {
  int n1, n2, i, j, k;
  int *l, *r;

  n1 = mid - left;
  n2 = right - mid;
  
  l = malloc((n1+1) * sizeof(int));
  r = malloc((n2+1) * sizeof(int));

  for (i = 0; i < n1; i++) {
    l[i] = data[left+i]; 
  }
  for (i = 0; i < n2; i++) {
    r[i] = data[mid+i];
  }
  l[n1] = MAX;
  r[n2] = MAX;
  
  i = 0;
  j = 0;

  for (k = left; k < right; k++) {
    if (l[i] <= r[j]) {
      data[k] = l[i];
      i++;
      count++;
    }
    else {
      data[k] = r[j];
      j++;
      count++;
    }
  }
}

void mergeSort(int *data, int left, int right) {
  int mid;
  if (left+1 < right) {
    mid = (left + right) / 2;
    mergeSort(data, left, mid);
    mergeSort(data, mid, right);
    merge(data, left, mid, right);
  }
}

