#include<stdio.h>
#include<stdlib.h>
#define INFTY 1000000000
int count=0;

void merge(int *a,int left,int mid,int right){
  int n1,n2,l[500000],r[500000];
  int i,j,k;

  n1 = mid-left;
  n2 = right-mid;
  for(i=0;i<n1;i++) l[i] = a[left+i];
  for(i=0;i<n2;i++) r[i] = a[mid+i];
  l[n1] = INFTY;
  r[n2] = INFTY;
  i=0;
  j=0;
  
  for(k=left;k<right;k++){
    if(l[i]<=r[j]){
      count++;
      a[k] = l[i];
      i++;
    }
    else{
      count++;
      a[k] = r[j];
      j++;
    }
  }
}

void mergeSort(int *a, int left, int right){
  int mid;

  if(left+1<right){
    mid = (left+right)/2;
    mergeSort(a, left, mid);
    mergeSort(a, mid, right);
    merge(a, left, mid, right);
  }
}

int main(){
  int n,a[510000];
  int left,right;
  int i;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  left = 0;
  right = n;

  mergeSort(a,left,right);
  for(i=0;i<n;i++){
  printf("%d",a[i]);
  if(i!=n-1) printf(" ");
  else printf("\n");
  }
  printf("%d\n",count);
  
  return 0;
}

