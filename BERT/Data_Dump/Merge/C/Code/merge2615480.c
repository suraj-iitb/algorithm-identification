#include <stdio.h>
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2],R[MAX/2+2];
int cnt;

void merge(int a[],int n,int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++){
    L[i]=a[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=a[mid+i];
  }
  L[n1]=R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]){
      a[k]=L[i++];
    }
    else{
      a[k]=R[j++];
    }
  }
}

void mergesort(int a[],int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergesort(a,n,left,mid);
    mergesort(a,n,mid,right);
    merge(a,n,left,mid,right);
  }
}

int main(void)
{
  int a[MAX],n,i;
  cnt=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  mergesort(a,n,0,n);
  
  for(i=0;i<n;i++){
    if(i>0){
      printf(" ");
    }
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}
