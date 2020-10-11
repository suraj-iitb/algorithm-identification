#include<stdio.h>
#include<math.h>
#define INFINITY 1000000000
void merge(int*,int,int,int);
void mergesort(int*,int,int);

int count=0;

int main(){

  int i;
  int n;
  int left,right;
  
  scanf("%d",&n);
  int N[n];
  for(i=0;i<n;i++){
    scanf("%d",&N[i]);
  }
  left=0;
  right=n;
  mergesort(N,left,right);
  for(i=0;i<n;i++){
    if(i==n-1) printf("%d\n",N[i]);
    else printf("%d ",N[i]);
  }
  printf("%d\n",count);
  return 0;
}
void merge(int *N,int left,int mid,int right){

  int i,j,k;
  int r,l;
  l=mid-left;
  r=right-mid;
  int L[l],R[r];
  for(i=0;i<l;i++){
    L[i]=N[left+i];
  }
  for(i=0;i<r;i++){
    R[i]=N[mid+i];
  }
  L[l]=INFINITY;
  R[r]=INFINITY;
  
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<R[j]){
      N[k]=L[i];
      i++;
    }
    else{
      N[k]=R[j];
      j++;
    }
  }
}
void mergesort(int *N,int left,int right){

  int mid,i;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(N,left,mid);
    mergesort(N,mid,right);
    merge(N,left,mid,right);
  }
}

