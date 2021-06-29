#include <stdio.h>
#define INFTY 1000000001

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int cnt = 0;

int main(){
  int A[500001];
  int n, left, right;
  int i;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  left = 0;
  right = n;

  
  mergeSort(A, left, right);

  for(i = 0; i < n; i++){
    printf("%d", A[i]);

    if(i < n - 1) printf(" ");
    else printf("\n");
  }

  printf("%d\n", cnt);
  
  return 0;
  
}

void merge(int *A, int left, int mid, int right){
  int i, j, k;
  int L[250001], R[250001];
  int n1, n2;
  
  n1 = mid - left;
  n2 = right - mid;
  
  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }



  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  
  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for(k = left; k < right ; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];

      i++;
    }

    else{
      A[k] = R[j];

      j++;
    }

    cnt++;
  }
}

void mergeSort(int *A, int left, int right){
  int mid;
  int i;
  
  
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

