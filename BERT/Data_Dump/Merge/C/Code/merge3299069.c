#include<stdio.h>
#define INFTY 1000000000
#define N 500005


void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count=0;

int main(){
  int n,i,right,left=0,A[N];
  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  right = n;

  mergeSort(A,left,right);

  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i < n - 1){
      printf(" ");
    }
    if(i == n -1){
      printf("\n");
    }
  }
  printf("%d\n",count);
  
  return 0;
}

void merge(int A[],int left, int mid, int right){
  int n1,n2,L[N],R[N],i,j,k;

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
  i = 0;
  j = 0;

  for(k=left;k<right;k++){
    count = count + 1;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[],int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}

