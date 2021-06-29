#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int count = 0;

int main()
{
  int n, s[500000];
  int i;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &s[i]);
  }

  mergeSort(s, 0, n);

  for(i = 0; i < n; i++){
    printf("%d", s[i]);
    if(i != n-1) printf(" ");
    else printf("\n");
  }
  printf("%d\n", count);
  return 0;
}


void merge(int *a, int left, int mid, int right){
  int n1, n2, *l, *r;
  int i, j, k;
  n1 = mid - left + 1;
  n2 = right - mid + 1;
  l = (int *)malloc(sizeof(int) * n1);
  r = (int *)malloc(sizeof(int) * n2);
  for(i = 0; i < n1; i++){
    l[i] = a[left + i];
  }
  for(i = 0; i < n2; i++){
    r[i] = a[mid + i];
  }
  l[n1 - 1] = INFINITY;
  r[n2 - 1] = INFINITY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    count++;
    if(l[i] <= r[j]){
      a[k] = l[i];
      i++;
    }
    else{
      a[k] = r[j];
      j++;
    }
  }
}


void mergeSort(int *a, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

