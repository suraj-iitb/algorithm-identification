#include <stdio.h>
#define N 500000
#define INFTY 1000000001

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int count = 0;

int main(){
  int n = 0;
  int i = 0;
  int S[N];

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S, 0, n);

  for(i = 0; i < n; i++){
    
    printf("%d",S[i]);
    if(i == n-1)printf("\n");
    else printf(" ");
    
  }

  printf("%d\n",count);
  
  return 0;
}

void merge(int *A, int left, int mid, int right){
  int n1 = 0, n2 = 0;
  int i = 0, j = 0, k = 0;
  int L[(N/2)+1], R[(N/2)+1];

  n1 = mid - left;
  n2 = right - mid;

  /*L[], R[]*/
  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }

  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }

  /* 番兵 */
  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for(k = left; k < right; k++){
    
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++;
    }
    
    else{
      A[k] = R[j];
      j++;
      count++;
    }
    
  }

}

void mergeSort(int *A, int left, int right){
  int mid = 0;
  
  if(left+1 < right){
    
    mid = (left + right) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
    
  }

}

