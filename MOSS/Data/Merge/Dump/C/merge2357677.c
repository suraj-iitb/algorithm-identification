#include <stdio.h>
#include <limits.h>

void merge(int,int,int);
void mergeSort(int,int);

#define MAX 500000

int A[MAX],L[MAX],R[MAX],N,count=0,left=0,right;

int main(){
  int i;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  right=N;
  mergeSort(left,right);

  for (i=0;i<N-1;i++){
    printf("%d ", A[i]);
  }

  printf("%d\n",A[N-1]);
  printf("%d\n",count);

  return 0;
}


void merge(int left,int mid,int right){
  int n1,n2,k,i,j;
  n1 = mid - left;
  n2 = right - mid;
  //L[0...n1], R[0...n2] ?????????
  for( i = 0 ;i< n1;i++){
    L[i] = A[left + i];
  }
  for(i = 0;i<n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i = 0;
  j = 0;
  for(k = left ;k<right;k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
  }

}

void mergeSort(int left,int right){
  int mid;
  if(left+1<right){
    mid = (left + right)/2;
    mergeSort(left, mid);
    mergeSort(mid, right);
    merge(left, mid, right);

  }

}
