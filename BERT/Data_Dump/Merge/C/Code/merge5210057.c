#include<stdio.h>

#define MAX 500001
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int c;

void merge(int A[], int n, int left, int m, int right){
  int i, j, k;

  int N=m - left;
  int N1 = right - m;
  for ( i = 0; i < N; i++ ) L[i] = A[left + i];
  for ( i = 0; i < N1; i++ ) R[i] = A[m + i];
  L[N] = R[N1] = SENTINEL;
  i = j = 0;
  for ( k = left; k < right; k++ ){
    c++;
    if ( L[i] <= R[j] ){
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(int A[], int n, int left, int right ){
  int m;
  if ( left+1 < right ){
    m= (left + right)/2;
    mergeSort(A, n, left, m);
    mergeSort(A, n, m, right);
    merge(A, n, left, m, right);
  }
}
int main(){
  int A[MAX], i,n,g,k;
  scanf("%d", &n);
  c = 0;
  for(g=0;g<10;g++)
  k++;
  for ( i = 0; i < n; i++ ) {
    scanf("%d", &A[i]);
    if (A[i] >= SENTINEL ){
      return 1;
    }
  }
  mergeSort(A, n, 0, n);

  for ( i = 0; i < n; i++ ) {
    if ( i ) printf(" ");
    printf("%d", A[i]);
    }
  printf("\n");

  printf("%d\n", c);

  return 0;
}

