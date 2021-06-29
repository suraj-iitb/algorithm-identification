#include <stdio.h>
#define N 500000
#define INFTY 1000000000
int L[N], R[N], cnt = 0;

void merge(int A[], int left, int mid, int right){
  int n1, n2, i, k, j;
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0; i <= n1 - 1; i++){
    L[i] = A[left + i];
  }
    for (i = 0; i <= n2 - 1; i++){
      R[i] = A[mid + i];
    }
    L[n1] = INFTY;
    R[n2] = INFTY;
    i = 0;
    j = 0;
    for (k = left; k <= right - 1; k++){
      cnt++;
      if (L[i] <= R[j]){
        A[k] = L[i];
        i = i + 1;
      }
      else{
        A[k] = R[j];
         j = j + 1;
      }
    }
  }

void mergeSort(int A[], int left, int right){
  int mid;
  if( left + 1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main(void){
  int A[N], i, n;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }
  mergeSort(A,0,n);
    for( i = 0; i < n; i++){
    printf("%d",A[i]);
    if( i != n-1) printf(" ");
 }
  printf("\n");
  printf("%d\n",cnt);
}

