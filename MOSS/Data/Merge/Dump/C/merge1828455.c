#include<stdio.h>
#define SENTINEL 2000000000
#define N 500000

int  L[N/2+2],R[N/2+2];
int count=0;

void Merge(int A[],int n,int left,int mid,int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;

  for(i=0;i<n1;i++){
    L[i] = A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid+i];
  }

  L[n1]=R[n2]=SENTINEL;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    count++;
    if(L[i]<=R[j]){
      A[k] = L[i++];
    }else{
      A[k]=R[j++];
    }
  }
}

void MergeSort(int A[],int n,int left,int right){
    if(left+1 < right){
      int mid=(left+right)/2;
      MergeSort(A,n,left,mid);
      MergeSort(A,n,mid,right);
      Merge(A,n,left,mid,right);
    }
}

int main(){
  int i,n,A[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }  
  MergeSort(A,n,0,n);
  
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i<n-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}
