#include<stdio.h>
#include<stdlib.h>

#define N 500000
#define INFTY 2000000000

int cnt;
int n;

void merge(int*, int, int, int);
void merge_sort(int*, int, int);

int main(){

  int i, a[N];

  cnt = 0;

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&a[i]);
  
  merge_sort(a, 0, i);

  printf("%d",a[0]);

  for(i=1;i<n;i++)printf(" %d",a[i]);

  printf("\n%d\n",cnt);

  return 0;
}
void merge(int *a, int left, int mid, int  right){
  int n1, n2, i, k, j;
  int L[n], R[n];

  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<n1;i++)L[i] = a[left + i];
  
  for(i=0;i<n2;i++)R[i] = a[mid + i];

  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      a[k] = L[i];
      i = i+1;
      cnt++;
    }
    else{
      a[k] = R[j];
      j = j+1;
      cnt++;
    }
  }
}
void merge_sort(int *a, int left, int right){
  int mid;

  if(left+1<right){
    mid = (left + right)/2;
    merge_sort(a, left, mid);
    merge_sort(a, mid, right);
    merge(a, left, mid, right);
  }
}
