#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

int compcount;

void merge(int *A, int l, int m, int r){
  int n1,n2,i,j,k;
  int *L, *R;

  n1 = m-l;
  n2 = r-m;
  L = (int *)malloc(sizeof(int) * (n1+1));
  R = (int *)malloc(sizeof(int) * (n2+1));

  // divide
  for(i=0; i<n1; i++) L[i] = A[l+i];
  for(i=0; i<n2; i++) R[i] = A[m+i];
  L[n1] = INF;
  R[n2] = INF;

  // merge
  i=0;
  j=0;
  for(k=l; k<r; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      compcount++;
    }
    else {
      A[k] = R[j];
      j++;
      compcount++;
    }
  }

  free(L);
  free(R);

}

void mergeSort(int *A, int l, int r){
  int m;
  if(l+1 < r){
    m = (l+r) / 2;
    mergeSort(A,l,m);
    mergeSort(A,m,r);
    merge(A,l,m,r);
  }
}

int main(){
  int n,i;
  int *arr;

  // input and alloc
  scanf("%d",&n);
  arr = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++) scanf("%d",&arr[i]);

  // sort
  mergeSort(arr,0,n);

  // output
  for(i=0; i<n; i++){
    if(i == n-1) printf("%d",arr[i]);
    else printf("%d ",arr[i]);
  }
  printf("\n%d\n",compcount);

  free(arr);

  return 0;
}
