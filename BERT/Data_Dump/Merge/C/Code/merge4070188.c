#include <stdio.h>
#define N 1000000000

void merge(int*,int,int,int,int);
void mergesort(int*,int,int,int);

int L[500000], R[500000], count;

int main()
{
  int n, S[500000], i;
  count = 0;
  scanf("%d",&n);
  for (i = 0; i < n; i++)
    scanf("%d",&S[i]);
  mergesort(S,n,0,n);
  for (i = 0; i < n; i++){
    printf("%d",S[i]);
    if (i < n-1)
      printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}

void merge(int A[], int n, int left, int mid, int right)
{
  int i, j, k;

  for (i = 0; i < mid-left; i++)
    L[i] = A[left+i];
  for (i = 0; i < right-mid; i++)
    R[i] = A[mid+i];
  L[mid-left] = R[right-mid] = N;
  i = j = 0;
  for (k = left; k < right; k++){
    count++;
    if (L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergesort(int A[], int n, int left, int right)
{
  int mid;
  if (left+1 < right){
    mid = (left+right)/2;
    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

