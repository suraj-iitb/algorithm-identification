#include <stdio.h>
#include <math.h>
#define N 500000

void merge(int [], int, int, int);
void mergeSort(int [], int, int);

int m = 0;

int main(){
  int a[N];
  int left, right, mid;
  int n, i;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  mergeSort(a, 0, n);

  printf("%d", a[0]);
  for(i = 1; i < n; i++){
    printf(" %d", a[i]);
  }
  printf("\n%d\n", m);
  return 0;
}

void merge(int a[], int left, int mid, int right){
  int i, j, k;
  int n1, n2;
  n1 = mid - left;
  n2 = right - mid;
  int l[n1], r[n2];
  for(i = 0; i <= n1-1; i++){
    l[i] = a[left + i];
  }
  for(i = 0; i <= n2-1; i++){
    r[i] = a[mid + i];
  }
  l[n1] = 2147483647;
  r[n2] = 2147483647;
  
  
  
  i = 0;
  j = 0;
  
  for(k = left; k <= right-1; k++){
    if(l[i] <= r[j]){
      a[k] = l[i];
      i = i + 1;
      m++;
    }else{
      a[k] = r[j];
      j = j + 1;
      m++;
    }
    
  }
}

void mergeSort(int a[], int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}


