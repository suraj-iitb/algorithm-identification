#include<stdio.h>
#define INFINITY (1<<30)
#define N 500000
int n,cnt = 0;
void merge(int *A, int left, int mid, int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1], R[n2+1];
  for(i = 0; i < n1; i++) L[i] = A[left + i];
  for(i = 0; i < n2; i++) R[i] = A[mid + i];
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      cnt++;
    }else{
      A[k] = R[j];
      j++;
      cnt++;
    }
  }
}
void mergeSort(int *A, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
int main(){
  int i;
  int a[N];
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&a[i]);
  mergeSort(a,0,n);
  for(i = 0; i < n; i++){
    if(i != n - 1) printf("%d ",a[i]);
    else printf("%d",a[i]);
  }
  printf("\n%d\n",cnt);
  return 0;
}


