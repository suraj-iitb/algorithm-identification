#include<stdio.h>
#include<math.h>
#define INFINITY 100000000000000000;

int A[500000],sum=0;
void mergeSort(int,int);

int main(){
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  mergeSort(0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",sum);

  return 0;
}

void merge(int left,int mid, int right){
  int i,j,k,n1,n2;
  n1=mid-left;
  n2=right-mid;
  int L[n1+1],R[n2+1];
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=INFINITY;
  R[n2]=INFINITY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    sum+=1;
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }
  }
}

void mergeSort(left,right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
}
