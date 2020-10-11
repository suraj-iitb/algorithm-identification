#include <stdio.h>
#define INFTY 2147483647
#define N 500000
int L[N/2+2], R[N/2+2];
int cnt;
void merge(int *, int, int, int, int);
void mergeSort(int *, int, int, int);

int main(){
  int S[N], i;
  int n;
  cnt = 0;
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }
  mergeSort(S, n, 0, n);
  for(i=0; i<n; i++){
    if( i==n-1 ) {
      printf("%d\n", S[i]); 
    }
    else printf("%d ", S[i]);
  }
  printf("%d\n", cnt);
  return 0;
}


void mergeSort(int *S, int n, int left, int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(S, n, left, mid);
    mergeSort(S, n, mid, right);
    merge(S, n, left, mid, right);
  }
}

void merge(int *S, int n, int left, int mid, int right){
  int n1,n2;
  int i, j, k;
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0; i < n1; i++){
    L[i] = S[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = S[mid + i];
  }
  L[n1] = R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++) {
    cnt++;
    if(L[i] <= R[j]){
      S[k] = L[i];
      i = i + 1;
    }
    else {
      S[k] = R[j];
      j = j + 1;
    } 
  }
}

