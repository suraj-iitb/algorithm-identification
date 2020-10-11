#include<stdio.h>
#define INFTY 2000000000;
int n,sum=0;
void mergesort(int*,int,int);
void merge(int*,int,int,int);
int main(){
  int i,a[500000],left,right;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  left=0; right=n;
  mergesort(a,left,right);
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",sum);
  return 0;
}
void mergesort(int a[],int left, int right){
  int mid;
  if((left+1)<right){
    mid=(left+right)/2;
    mergesort(a,left,mid);
    mergesort(a,mid,right);
    merge(a,left,mid,right);
  }
}
void merge(int a[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid-left;
  n2 = right-mid;
  int l[n1+1],r[n2+1];
  for(i=0;i<n2;i++){
    r[i]=a[mid+i];
  }
  for(i=0;i<n1;i++){
    l[i]=a[left+i];
  }
  l[n1]=r[n2]=INFTY;
  i=j=0;
  for(k=left;k<right;k++){
    sum++;
    if(l[i]<=r[j]){
      a[k]=l[i];
      i++;
    }
    else{
      a[k]=r[j];
      j++;
    }
  }
}

