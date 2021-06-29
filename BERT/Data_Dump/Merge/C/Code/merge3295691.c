#include<stdio.h>
#define MAX 500000
#define INFTY 1000000000
int cnt,L[MAX/2+2],R[MAX/2+2];

void merge(int A[],int left,int mid,int right){
  int i,k,j;
  int n1 = mid - left;
  int n2 = right - mid;
  // L[0...n1], R[0...n2] を生成
  for(i = 0;i<n1;i++){
    L[i] = A[left + i];
  }
  for( i = 0;i< n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left;k<right;k++){
    cnt++;
    if( L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int A[],int n,int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,n, left, mid);
    mergeSort(A,n, mid, right);
    merge(A, left, mid, right);
  }
}
int main(){
  int A[MAX],n,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,n,0,n);
  for(i=0;i<n;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}
	  
    

