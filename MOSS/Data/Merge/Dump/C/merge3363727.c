#include <stdio.h>
#define MAX 500000
#define INFTY 2000000000

int L[MAX/2+2], R[MAX/2+2];
int count, n;

void merge(int A[],int left,int mid,int right)
{

  int n1, n2, i, j, k;
  
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
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{ 
      A[k] = R[j];
      j = j + 1;
    }
  }
  
}

void mergeSort(int A[],int left,int right)
{

  int mid;
  
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }

}

int main()
{

  int A[MAX];
  int i;

  count = 0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  mergeSort(A,0,n);

  for(i=0;i<n;i++){
    if(i != n-1) printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }

  printf("%d\n",count);

  return 0;

}

