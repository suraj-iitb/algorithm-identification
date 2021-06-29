#include<stdio.h>
#include<stdlib.h>
#define INFTY 1000000000
void merge(int *,int ,int ,int );
void mergeSort(int *,int ,int );
int sum =0;

int main(){
  int *T;
  int n,i;
  int left,right;
  
  scanf("%d",&n);
  T = malloc(n*sizeof(int *));
  for(i=0 ; i<n ; i++) scanf("%d",&T[i]);

  left = 0;
  right = n;
  
  mergeSort(T,left,right);
 
  for(i=0 ; i<n-1 ; i++) printf("%d ",T[i]);
  printf("%d\n",T[n-1]);
  printf("%d\n",sum);

  return 0;
}


void merge(int *A,int left,int mid,int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1], R[n2];
  
  for(i=0 ; i<n1 ; i++) L[i] = A[left + i];
  for(i=0 ; i<n2 ; i++) R[i] = A[mid + i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for(k=left ; k<right ; k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      sum++;
    }
    else{ 
      A[k] = R[j];
      j = j + 1;
      sum++;
    }
  }
}

void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
