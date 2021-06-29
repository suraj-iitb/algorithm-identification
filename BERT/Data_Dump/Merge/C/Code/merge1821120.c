#include <stdio.h>


void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count;
int main(){
  int n;
  int i;
  
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);

  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }

  printf("%d\n%d\n",S[n-1],count);
  return 0;

}


void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }

}

void merge(int *A,int left,int mid,int right){
  int i,k,j;
  int n1=mid-left;
  int n2=right-mid;
  int L[n1+1];
  int R[n2+1];
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
    if(L[i]<=R[j]){
      A[k]=L[i];
      count++;
      i=i+1;
    }
    else{
      A[k]=R[j];
      j=j+1;
      count++;
    }

  }
}
