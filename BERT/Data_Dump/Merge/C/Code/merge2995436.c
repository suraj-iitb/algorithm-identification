#include <stdio.h>
#define INFTY 1000000000
#define N 500000
void mergeSort(int *A,int left,int right);
void merge(int *A,int left,int mid,int right);
int cnt=0,n;

int main(){
  int i,A[N];

  scanf("%d",&n);
  if(n <= 0 || n > 500001)
    printf("Error\n");

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
  for(i=0;i<n;i++){
    if(i == (n-1)) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
  printf("%d\n",cnt);
  return 0;
}

void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  int L[N],R[N];
  
  n1 = mid - left;
  n2 = right - mid;
  for(i=0;i<n1;i++){
    L[i] = A[left + i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY; 
  R[n2] = INFTY;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i] <= R[j]){
      cnt++;
      A[k] = L[i];
      i++;
    }
    else{
      cnt++;
      A[k] = R[j];
      j++;
    }
  }
  
  
}

