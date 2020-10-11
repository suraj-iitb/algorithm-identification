#include<stdio.h>
#define N 2100000000
#define M 500000

int cnt=0,a[M];

void merge(int left, int mid, int right){
  int i, j, k, n1=mid-left, n2=right-mid, L[n1+1], R[n2+1];
  
  for(i=0;i<n1;i++) L[i]=a[left+i];
  for(i=0;i<n2;i++) R[i]=a[mid+i];
  L[n1]=R[n2]=N;
  i=j=0;
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

void sort(int left, int right){
  if(left+1<right){
    int mid=(left+right)/2;
    sort(left,mid);
    sort(mid,right);
    merge(left,mid,right);
  }
}

int main(){
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  
  sort(0,n);

  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);

  printf("%d\n",cnt);
  
  return 0;
}

