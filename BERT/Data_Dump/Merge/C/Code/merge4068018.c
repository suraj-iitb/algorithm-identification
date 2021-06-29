#include<stdio.h>
#include<math.h>

#define N 500000
#define INFTY 1000000000
int count=0;
void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int main(){
  int a,i,A[N];

  scanf("%d",&a);
  for(i=0;i<a;i++)
    scanf("%d",&A[i]);
  mergeSort(A,0,a);
  
  for(i=0;i<a-1;i++)
    printf("%d ",A[i]);
  printf("%d",A[i]);
  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
}

void merge(int *A, int left, int mid, int right){
  int n,n1,n2,i,j,k,L[N],R[N];

  n1 = mid - left;
  n2 = right - mid;
  //L[0...n1], R[0...n2] を生成
  for(i=0;i<n1;i++)
    L[i] = A[left + i];

  for(i=0;i<n2;i++)
    R[i] = A[mid + i];

  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k=left;k<right;k++){
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

void mergeSort(int *A, int left, int right){
  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

