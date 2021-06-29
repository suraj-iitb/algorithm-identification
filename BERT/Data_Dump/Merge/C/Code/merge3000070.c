#include<stdio.h>
void merge(int *,int,int,int,int);
void mergeSort(int *, int,int,int);
#define MAX 500000
#define INFTY 2000000000

int L[MAX/2+2],R[MAX/2+2];
int count;
int main( ){
  int A[MAX],i,j,k,n;

  scanf("%d",&n);
  count = 0;
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
    if(A[i] >= INFTY){
      return 1;
    }
  }

  mergeSort(A,n,0,n);

  for(i = 0; i < n; i++){
    if(i) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
 
  return 0;
}

void merge(int A[], int n ,int left, int mid, int right){
  int i,j,k;
  int  n1 = mid - left;
  int  n2 = right - mid;
  // L[0...n1], R[0...n2] を生成
  for (i = 0 ;i < n1; i++){
    L[i] = A[left + i];
  }
  for( i = 0 ;i < n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    count++;
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else {
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int A[], int n ,int left, int right){
  if (left+1 < right){
    int mid = (left + right)/2;
    mergeSort(A,n, left, mid);
    mergeSort(A,n, mid, right);
    merge(A, n,left, mid, right);
  }
}



