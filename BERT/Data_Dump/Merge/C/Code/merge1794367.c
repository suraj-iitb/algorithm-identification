#include <stdio.h>

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count=0;

int main(){
  int S[1000000];
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    if(i != n-1){
      printf("%d ",S[i]);
    }
    else{
      printf("%d\n%d\n",S[i],count);
    }
  }

  return 0;

}

void merge(int *A,int left,int mid,int right){


  
  int n1,n2,i,j,k;

  n1=mid-left;
  n2=right-mid;

  int L[n1+1],R[n2+1];

  for(i=0;i<n1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }

  L[n1]=1000000000;
  R[n2]=1000000000;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    count++;
    if(L[i] <= R[j]){
      A[k]=L[i];
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
    }
  }



}


void mergeSort(int *A,int left,int right){

  int mid;

  if(left+1 < right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
