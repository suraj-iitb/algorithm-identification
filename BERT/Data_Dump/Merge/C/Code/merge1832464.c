#include <stdio.h>
#define MAX 500000
#define SENTINEL 2000000000
 
int l[MAX/2+2], r[MAX/2+2];
int cnt;
 
void merge(int [], int, int, int, int);
void mergeSort(int [], int, int, int);
 
int main(){
  int a[MAX], n, i;
 
  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &a[i]);
  }
  mergeSort(a, n, 0, n);
  for(i = 0;i < n;i++){
    if(i) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  printf("%d\n", cnt);
  return 0;
}
 
void merge(int a[], int n, int left, int mid, int right){
  int n1, n2, i, j, k;
 
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0;i < n1;i++){
    l[i] = a[left+i];
  }
  for(i = 0;i < n2;i++){
    r[i] = a[mid+i];
  }
  l[n1] = r[n2] = SENTINEL;
  i = j = 0;
  for(k = left;k < right;k++){
    cnt++;
    if(l[i] <= r[j]){
      a[k] = l[i++];
    }
    else a[k] = r[j++];
  }
}
 
void mergeSort(int a[], int n, int left, int right){
  int mid;
 
  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(a, n, left, mid);
    mergeSort(a, n, mid, right);
    merge(a, n, left, mid, right);
  }
}
