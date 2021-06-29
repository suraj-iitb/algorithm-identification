#include<stdio.h>
#define N 500000
#define INFTY 1000000005

void merge(int*, int, int, int);
void mergeSort(int*, int, int);

int cnt = 0;

int main(){
  int n, i, S[N];

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &S[i]);
  }

  mergeSort(S, 0, n);

  for(i = 0; i < n; i++){
    printf("%d", S[i]);
    if(i == n - 1)break;
    printf(" ");
  }
  printf("\n%d\n", cnt);
  
    return 0;
}

void mergeSort(int* A, int left, int right){
  int mid;
  
  if (left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

void merge(int* A, int left, int mid, int right){
  int n1, n2, i, j, k;
  static int L[N+1], R[N+1];
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
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
       A[k] = L[i];
       i = i + 1;
       cnt++;
       }
    else{
      A[k] = R[j];
      j = j + 1;
      cnt++;
    }
  }
}
  


