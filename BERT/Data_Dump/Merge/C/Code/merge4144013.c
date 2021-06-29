#include <stdio.h>

#define M 1000000

#define INFTY 999999999

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int cnt;

int main(){
  int num,A[M],i;
  
  scanf("%d",&num);
  for(i=0;i<num;i++) scanf("%d",&A[i]);
  mergeSort(A,0,num);
  
  for(i=0;i<num-1;i++)printf("%d ",A[i]);
  printf("%d\n",A[i]);
  printf("%d\n",cnt);
  return 0;
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k,L[M],R[M];

  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<n1;i++) L[i] = A[left + i];
  for(i=0;i<n2;i++) R[i] = A[mid + i];

  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;

  for(k=left;k<right;k++){
    if( L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      cnt++;
    }else{ 
      A[k] = R[j];
      j = j + 1;
      cnt++;
    }
  }

}

void mergeSort(int *A,int left,int right){
  int mid;

  if( left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

