#include <stdio.h>
#define SENTINEL 1000000000
#define MAX 500000
int count=0,n;
void Merge(int x[],int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int i,j,k;
  int L[n1],R[n2];
  for(i=0;i<n1;i++){
    L[i]=x[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=x[mid+i];
  }
  L[n1]=SENTINEL;
  R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      x[k]=L[i];
      i++;
    }
    else{
      x[k]=R[j];
      j++;
    }
    count++;
  }
}
void Merge_Sort(int x[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    Merge_Sort(x,left,mid);
    Merge_Sort(x,mid,right);
    Merge(x,left,mid,right);
  }
}
int main(){
  int i;
  scanf("%d",&n);
  int x[n];
  for(i=0;i<n;i++){
    scanf("%d",&x[i]);
  }
  Merge_Sort(x,0,n);
  for(i=0;i<n;i++){
    printf("%d",x[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",count);
  return 0;
}
