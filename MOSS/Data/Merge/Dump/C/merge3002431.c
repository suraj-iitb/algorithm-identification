#include<stdio.h>
#define INFTY 2100000001
int L[500000], R[500000];
int cnt = 0;
void merge(int *a,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0;i < n1; i++){
     L[i] = a[left + i];
   }
  for(i = 0;i < n2; i++){
    R[i] = a[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for( k = left; k < right; k++){
    if(L[i] <= R[j]){
       a[k] = L[i];
       i++;
       cnt++;
     }else{
       a[k] = R[j];
       j++;
       cnt++;
     }
  }
}
void mergeSort(int *a, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }
}
int main(){
  int n,a[500001],i;
  scanf("%d",&n);
  for(i =0;i < n;i++) scanf("%d",&a[i]);
  mergeSort(a,0,n);
  for(i =0;i < n - 1;i++) printf("%d ",a[i]);
  printf("%d",a[i]);
  printf("\n%d\n",cnt);
  return 0;
}

