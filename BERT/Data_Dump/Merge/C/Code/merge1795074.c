#include <stdio.h>

#define N 500000

int A[N],R[N/2+2],L[N/2+2];
int c;
void merge(int*,int,int,int);
void mergeSort(int*,int,int);

int main(){

  int n,i,j;
  int left,right;

  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&A[i]);
  }

  left = 0;
  right = n;

  mergeSort(A,left,right);

  for(i=0; i<n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);

  printf("%d\n",c);

  return 0;
}

void merge(int* A,int left,int mid,int right){

  int n1,n2,i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  for(i=0; i<n1; i++){
    L[i] = A[left+i];
  }

  for(i=0; i<n2; i++){
    R[i] = A[mid+i];
  }
  L[n1] = 2000000000;
  R[n2] = 2000000000;

  i=0;
  j=0;

  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      c++;
    }
    else{
      A[k] = R[j];
      j++;
      c++;
    }
  }

}

void mergeSort(int* A,int left,int right){

  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
