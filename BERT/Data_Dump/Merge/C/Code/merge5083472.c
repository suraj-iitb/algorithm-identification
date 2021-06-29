#include<stdio.h>
#include<stdlib.h>

#define nMAX 500000
#define INFINITY 1000000000

void merge(int A[], int left, int mid, int right);
void mergeSort(int A[], int left, int right);

int count = 0, S[nMAX];

int main(){
  int i, n;
  
  scanf("%d", &n);

  /*Sの要素の入力*/
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]);

  mergeSort(S, 0, n);

  /*マージソート後のSの出力*/
  for(i = 0; i < n; i++){
    if(i != n-1) printf("%d ", S[i]);
    else printf("%d", S[i]);
  }
  printf("\n");
  
  printf("%d\n", count);

  return 0;
}

/*マージ*/
void merge(int A[], int left, int mid, int right){
  int i, j, k, n1, n2, L[mid - left], R[right - mid];
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1; i++)
    L[i] = A[left + i];
  for(i = 0; i < n2; i++)
    R[i] = A[mid + i];
  L[n1] = INFINITY;
  R[n2] = INFINITY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      count++;
    }
    else{
      A[k] = R[j];
      j = j + 1;
      count++;
    }
  }
}

/*マージソート*/
void mergeSort(int A[], int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (int)(left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}
