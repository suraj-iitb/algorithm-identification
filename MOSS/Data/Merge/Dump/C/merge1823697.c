#include <stdio.h>

#define N 500000
#define SENTINEL 1000000000;

int compareCount=0;

void Merge(int* ,int, int ,int );
void MergeSort(int* ,int ,int );

int main(){

  int n, A[N];
  int i;

  scanf("%d", &n);
  for(i=0;i<n;i++)
    scanf("%d", &A[i]);

  MergeSort(A, 0, n);


  printf("%d",A[0]);
  for(i=1;i<n;i++)
    printf(" %d", A[i]);

  printf("\n%d\n", compareCount);

  return 0;
}



void Merge(int* A,int left,int mid,int right){
  int l,r;
  int i, k;

  l = mid - left;
  r = right - mid;

  int L[N/2+2], R[N/2+2];

  for(i=0; i<l; i++)   L[i] = A[left + i];
  for(i=0; i<r; i++)   R[i] = A[mid + i];

  L[l] = SENTINEL;
  R[r] = SENTINEL;

  i = 0;
  int j = 0;

  for(k=left; k<right; k++){

    compareCount++;
    
    if( L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{
      A[k] = R[j];
      j = j + 1;
    }
    
  }
}
  
void MergeSort(int *A,int left,int right){
  
  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    MergeSort(A, left, mid);
    MergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}
