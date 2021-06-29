#include<stdio.h>

#define INFTY 1000000000

int p;

void merge(int A[], int left, int mid, int right){
  int n1,n2,i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  int L[n1], R[n2];

  for(i=0; i<n1; i++) L[i]=A[left+i];
  for(i=0; i<n2; i++) R[i]=A[mid+i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  i=0,j=0;

  for(k=left; k<right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
    p++;
  }
}


void mergeSort(int A[], int left, int right){
  if(left+1 < right){
    int mid = (left+right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(void){
  int n,i;
  p = 0;
  scanf("%d",&n);

  int S[n];
  for(i=0; i<n; i++) scanf("%d", &S[i]);

  mergeSort(S, 0, n);

  for(i=0; i<n-1; i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[n-1]);
  printf("%d\n",p);

  return 0;
}

