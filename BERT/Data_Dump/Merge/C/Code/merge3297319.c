#include<stdio.h>
#include<limits.h>

int count,L[250002],R[250002];

void merge(int *,int,int,int);
void mergeSort(int *,int,int,int);

int main(){
  int A[500000],i,n;
  count=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  mergeSort(A,n,0,n);
  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

void merge(int *A,int left,int mid,int right){
  int i,j,k;
  int n1 = mid-left;
  int n2 =right-mid;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=R[n2]=INT_MAX;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k]=L[i++];
    }
    else{
      A[k]=R[j++];
    }
  }
}

void mergeSort(int *A,int n,int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,left,mid,right);
  }
}

