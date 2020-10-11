#include<stdio.h>
#define INF 1000000001

int count;

void merge(int A[], int left, int mid, int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1];
  int R[n2 + 1];
  for(i=0; i<n1; i++){
    L[i] = A[left + i];
  }
  for(i=0; i<n2; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INF;
  R[n2] = INF;

  i=0;
  j=0;

  for(k=left; k<right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
    count ++;
  }
  
}

void mergeSort(int A[], int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int n,i;
  int A[500001];

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A, 0, n);

  for(i=0; i<n; i++){
    printf("%d",A[i]);
    if(i < n - 1){
      printf(" ");
    }
  }

  printf("\n%d\n",count);

  return 0;
}

