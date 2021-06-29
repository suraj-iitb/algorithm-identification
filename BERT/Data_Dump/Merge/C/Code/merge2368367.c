#include <stdio.h>
int A[500000],L[500000/2+2],R[500000/2+2],count=0;;

#define SENTINEL 2000000000
void merge(int*,int,int,int);
void mergeSort(int*,int,int);
  int main(){
  int n,i;

  scanf("%d",&n);

  for(i=0;i<n;i++)scanf("%d",&A[i]);

  mergeSort(A,0,n);
  for(i=0;i<n;i++){
    if(i!=0) printf(" ");
    printf("%d",A[i]);

  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}


void merge(int *A, int left,int mid,int right){
  int i,j,k,n1,n2;

  n1 = mid - left;
  n2 = right - mid;

  for( i = 0 ;i<n1;i++) L[i] = A[left + i];
  for (i = 0 ;i<n2;i++) R[i] = A[mid + i];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  i = 0;
  j = 0;
  for (k = left;k<right;k++){
    if (L[i] <= R[j]){
      count++;
      A[k] = L[i];
	i = i + 1;
    }
    else {
      count++;
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int *A,int left,int right){
  int mid;
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
