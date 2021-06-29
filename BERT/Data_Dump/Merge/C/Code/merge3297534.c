#include <stdio.h>
#define MAX 1000000000

int count,n,L[MAX/20],R[MAX/20];

void merge(int A[],int left,int mid,int right){
  int i,k;
  int n1 = mid - left;
  int n2 = right - mid;
  
  for(i=0;i<n1;i++)
    L[i] = A[left+i];
  for(i=0;i<n2;i++)
    R[i] = A[mid+i];
  
  L[n1] = MAX;
  R[n2] = MAX;
  int j=0;
  i = 0;
  
  for(k=left;k<right;k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int i,S[500000];

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);

  mergeSort(S,0,n);

  for(i=0;i<n-1;i++){
    printf("%d",S[i]);
    printf(" ");
  }
  printf("%d\n%d\n",S[i],count);

  return 0;
}
