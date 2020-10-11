#include <stdio.h>

int C=0;
int A[500000];

void merge(int *A, int l, int m, int r){
  int i, j, k;
  int n1= m - l, n2= r - m; 
  int L[n1], R[n2];
  for(i = 0; i < n1; i++){
    L[i] = A[l + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = A[m + i];
  }
  L[n1] = 1000000001;
  R[n2] = 1000000001;
  i = 0;
  j = 0;
  for(k = l; k < r; k++){
    C++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{ 
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int *A, int l, int r){
  int m;
  if(l+1 < r){
    m = (l + r)/2;
    mergeSort(A, l, m);
    mergeSort(A, m, r);
    merge(A, l, m, r);
  }
}


int main(){
  int n, i;
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  mergeSort(A, 0, n);
  for(i = 0; i < n-1; i++) printf("%d ", A[i]);
  printf("%d", A[i]);
  printf("\n%d\n", C);

  return 0;
}
