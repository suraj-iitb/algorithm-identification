#include <stdio.h>

#define NMAX 500000
#define AMAX 1000000000 

int L[NMAX/2+2], R[NMAX/2+2],cnt;


void merge(int *A, int left, int mid, int right){

  int i, j, k;

  int n = mid - left;
  int m = right - mid;

  for(i=0;i<n;i++) L[i] = A[left + i];
  for(i=0;i<m;i++) R[i] = A[mid + i];

  L[n] = R[m] = AMAX;

  i = 0;
  j = 0;
  for(k=left;k<right;k++){
    cnt++;
    if(L[i] <= R[j]){
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(int *A, int left, int right){

  if(left+1 < right){

    int mid = (left + right)/2;

    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);

  }
}


int main(){

  int m, A[NMAX], i;
  cnt = 0;

  scanf("%d", &m);

  for(i=0;i<m;i++) scanf("%d", &A[i]);

  mergeSort(A,0,m);

  for(i=0;i<m;i++){
    if(i) { printf(" "); }
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", cnt);

  return 0;
}

