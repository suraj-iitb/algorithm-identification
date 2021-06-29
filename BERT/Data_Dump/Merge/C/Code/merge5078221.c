#include <stdio.h>
#define N 500000//AOJ:add 0
#define INFTY 100000000000//AOJ:add 0

int L[N],R[N];
int cnt,n;


void merge(int A[], int left,int mid,int right){
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  /* L[0...n1], R[0...n2] を生成*/
  for (i = 0 ;i<n1;i++){
    L[i] = A[left + i];
  }
  for (i = 0 ;i<n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left;k<right;k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }else{
      A[k] = R[j];
      j = j + 1;
    }
    cnt++;
  }
}

void mergeSort(int A[],int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int i;
  int S[N];

  scanf("%d",&n);
  cnt=0;
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S,0,n);
  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[n-1]);
  printf("%d\n",cnt);
  return 0;
}
