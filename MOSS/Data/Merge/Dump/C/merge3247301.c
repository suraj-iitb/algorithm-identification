#include <stdio.h>
#define MAX 500001

void merge(int A[],int left,int mid,int right, int* count){
  int i,j,n1,n2;
  int L[MAX];
  int R[MAX];
  int k;

  n1 = mid -left;
  n2 = right - mid;

  for(i=0;i<n1;i++){
    L[i] = A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i]=A[mid+i];
  }
  L[n1] = 2e9;
  R[n2] = 2e9;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    (*count)++;
    if(L[i]<=R[j]){
      A[k] = L[i];
      i=i+1;
    }
    else{
      A[k] = R[j];
      j = j+1;
    }
  }
  return;
}

void mergeSort(int A[],int left,int right,int* count){
  int mid;
  if(left+1<right){
    mid = (left+right)/2;
    mergeSort(A,left,mid,count);
    mergeSort(A,mid,right,count);
    merge(A,left,mid,right,count);
  }
  return;
}

int main(){
  int n,i;
  int A[MAX];
  int count = 0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  mergeSort(A,0,n,&count);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1){
      printf(" ");
    }
    else {
      printf("\n");
    }
  }
  printf("%d\n",count);

return 0;

}

