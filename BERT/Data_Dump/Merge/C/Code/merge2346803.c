#include <stdio.h>
#include <limits.h>
int count=0;

void merge(int* a,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  int l[n1],r[n2];

  for(i=0;i<n1;i++)l[i]=a[left+i];
  for(i=0;i<n2;i++)r[i]=a[mid+i];
  l[n1]=INT_MAX;
  r[n2]=INT_MAX;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(l[i]<=r[j]){
      a[k]=l[i];
      i++;
      count++;
    }else {
      a[k]=r[j];
      j++;
      count++;
    }
  }
}
  
void mergeSort(int* a,int left,int right){
  int mid;
  mid=(left+right)/2;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }
}

int main(){
  int i,j,n;
  int a[500000];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);
  mergeSort(a,0,n);
  for(i=0;i<n-1;i++)printf("%d ",a[i]);
  printf("%d\n%d\n",a[i],count);
  return 0;
}
