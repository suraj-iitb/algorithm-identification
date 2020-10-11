#include <stdio.h>
#include <stdlib.h>

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count=0;

int main() {
  int i,n,A[1000000];

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&A[i]);

  mergeSort(A,0,n);

  for(i=0;i<n;i++) {
    if(i==n-1) printf("%d\n",A[i]);
    else printf("%d ",A[i]);
  }
    printf("%d\n",count);

  return 0;
}

void merge(int *A,int left,int  mid,int  right){
  int i,j,k,n1,n2;
  double *L, *R;

  n1 = mid - left;
  n2 = right - mid;
  /* L[0...n1], R[0...n2] を生成 */
  L = (double *)malloc(sizeof(double)*(n1+1));
  R = (double *)malloc(sizeof(double)*(n2+1));

  for(i = 0; i <= n1-1 ; i++) L[i] = A[left + i];
  for (i = 0 ;i <= n2-1 ; i++) R[i] = A[mid + i];
  L[n1] = 1.0/0.0;
  R[n2] = 1.0/0.0;
  i = 0;
  j = 0;
  for (k = left ; k <= right-1 ; k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count ++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
      count++;
    }
  }
  free(L);
  free(R);
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
