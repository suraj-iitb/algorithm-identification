#include <stdio.h>
#define MAX 10000000
#define INFTY 1000000000

int L[MAX], R[MAX];
int cnt;

void merge(int A[], int left, int mid, int right){
  	int i,  j,  k;

  	int n1 = mid - left;
  	int n2 = right - mid;
  	for ( i = 0; i < n1; i++ ) L[i] = A[left + i];
  	for ( i = 0; i < n2; i++ ) R[i] = A[mid + i];
  	L[n1] = INFTY;
  	R[n2] = INFTY;
  	i = 0;
  	j = 0;
  	for ( k = left; k < right; k++ ){
    	cnt++;
    	if ( L[i] <= R[j] ) A[k] = L[i++];
    	else A[k] = R[j++];
  	}
}

void mergeSort(int A[], int left, int right ){
  int mid;
  if ( left+1 < right ){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(){
  int  i, n, A[MAX];
  cnt = 0;
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    scanf("%d", &A[i]);
    if (A[i] >= INFTY ){
      return 1;
    }
  }
  mergeSort(A, 0, n);

  for ( i = 0; i < n; i++ ) {
    if ( i ) printf(" ");
    printf("%d", A[i]);
    }
  printf("\n");

  printf("%d\n", cnt);

  return 0;
}
