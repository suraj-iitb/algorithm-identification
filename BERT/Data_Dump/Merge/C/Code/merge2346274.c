#include<stdio.h>
#define NUM 500000
#define INFTY 1000000000

int L[NUM/2+2],R[NUM/2+2],count=0;

void merge(int A[], int left, int mid, int right){
  int n1,n2,i,j=0,k;

  n1 = mid-left;
  n2 = right - mid;

  for(i = 0; i < n1; i++)
    L[i] = A[left+i];

  for(i = 0; i < n2; i++)
    R[i] = A[mid+i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  i=0;

  for(k = left; k < right; k++){
    count++;

    if(L[i] <= R[j]){
      A[k] = L[i];
      i += 1;
    }

    else{
      A[k] = R[j];
      j += 1;
    }
  }
}

void mergeSort(int A[], int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left+right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int n,S[NUM],i;
   
  scanf("%d",&n);

  for(i = 0; i < n; i++)
    scanf("%d",&S[i]);

  mergeSort(S, 0, n);

  for(i = 0; i < n-1; i++)
    printf("%d ",S[i]);

  printf("%d\n",S[n-1]);

  printf("%d\n",count);

  return 0;

}
