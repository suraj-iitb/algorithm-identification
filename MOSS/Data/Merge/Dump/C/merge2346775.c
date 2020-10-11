#include <stdio.h>
#define N 500000
#define SENTINEL 1000000000

int count = 0;
void mergeSort(int*,int,int);
void merge(int*,int,int,int);

int main(){
  int S[N], n, i;
  scanf("%d",&n);
  for(i = 0; i < n; i++) scanf("%d",&S[i]);
  mergeSort(S, 0, n);
  for(i = 0; i < n; i++){
    printf("%d",S[i]);
    if(i < n - 1) printf(" ");
  }
  printf("\n%d\n",count);
  
  return 0;
}

void mergeSort(int* S, int left, int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}

void merge(int* S, int left, int mid, int right){
  int i, j, k, n1, n2, L[N], R[N];
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1; i++) L[i] = S[left+i];
  for(i = 0; i < n2; i++) R[i] = S[mid+i];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    count++;
    if(L[i] <= R[j]){
      S[k] = L[i];
      i += 1;
    }
    else{
      S[k] = R[j];
      j += 1;
    }
  }
}
