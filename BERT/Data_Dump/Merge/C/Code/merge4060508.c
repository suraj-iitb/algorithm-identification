#include<stdio.h>
#include<math.h>
#define N 500000
void merge(int[],int,int,int);
void mergeSort(int[],int,int,int);
int count;
int main(){
  int a,A[N],i;
  count=0;
  scanf("%d",&a);
  for(i=0;i<a;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,a,0,a);
  for(i=0;i<a-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);
  return 0;
}
void merge(int *A,int left,int mid,int right){
  int i,j,x;
  int inf=1000000000;
  int n1=mid-left;
  int n2=right-mid;
  int L[n1],R[n2];
  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1]=R[n2]=inf;
  i=0;
  j=0;
  for(x=left;x<right;x++){
    count++;
    if(L[i]<=R[j]){
      A[x]=L[i];
      i=i+1;
    }
    else{
      A[x]=R[j];
      j=j+1;
    }
  }
}
void mergeSort(int *A,int n,int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,left,mid,right);
  }
}

