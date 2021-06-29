#include <stdio.h>

#define MAX 500000
#define S 2000000000

void merge (int *, int, int, int, int);
void mergeSort (int *, int, int, int);

int l[MAX/2+2], r[MAX/2+2];
int count;

int main() {
  int a[MAX], n, i;

  count = 0;
  scanf("%d", &n);
  for(i = 0 ; i < n ; i++) {
    scanf("%d", &a[i]);
  }

  mergeSort(a, n, 0, n);

  for(i = 0 ; i < n ; i++) {
    printf("%d", a[i]);
    if(i != n-1) printf(" ");
  }
  printf("\n%d\n", count);

  return 0;
}

void merge(int *a, int n, int left, int mid, int right) {
  int n1 = mid - left;
  int n2 = right - mid;
  int i, j, k;
  
  for(i = 0 ; i < n1 ; i++) {
    l[i] = a[left + i];
  }
  for(i = 0 ; i < n2 ; i++) {
    r[i] = a[mid + i];
  }
  l[n1] = S;
  r[n2] = S;
  for (k = left, i = 0, j = 0; k < right ; k++) {
    count++;
    if(l[i] <= r[j]) {
      a[k] = l[i++];
    }
    else {
      a[k] = r[j++];
    }
  }
}

void mergeSort(int *a, int n, int left, int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(a, n, left, mid);
    mergeSort(a, n, mid, right);
    merge(a, n, left, mid, right);
  }
}
