#include <stdio.h>

#define MAX 500000
#define SENTINEL 2000000000

int cnt=0;
int A[MAX], L[MAX/2+2],R[MAX/2+2];

void merge(int A[], int left, int mid, int right){
 
  int i,j,k, sw=0;
  int n1 = mid - left;
  int n2 = right - mid;
  /* L[0...n1], R[0...n2] を生成 */
  for (i = 0; i<n1; i++)
    L[i] = A[left + i];
  for (i = 0; i < n2; i++)
    R[i] = A[mid + i];
  
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  
  i = 0;
  j = 0;
  for (k = left; k<right; k++){
    cnt++;
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

void mergeSort(int A[], int left, int right)
{
  if (left+1 < right){
    int mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}


void print(int A[], int N){
  int i;
  for ( i = 0; i < N; i++ ){
    if (i) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
}

int main( void )
{
  int n, i;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &A[i]);

  mergeSort(A,0,n);

  print(A,n);
  
  return 0;
}

