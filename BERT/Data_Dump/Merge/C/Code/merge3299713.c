#include <stdio.h>
#include <stdlib.h>

#define N 500000
#define INFTY 1000000005

void mergeSort(int *, int, int);
void Merge(int *,int, int, int);


int cnt, n;

int main () {
  int i, data[N];

  scanf("%d",&n);
 
  for(i = 0 ; i < n ; i++) {
    scanf("%d",&data[i]);
  }

  mergeSort(data, 0, n);

  for(i = 0 ; i < n ; i++) {
    if(i < n - 1) printf("%d ",data[i]);
    else printf("%d",data[i]);
  }

  printf("\n%d\n",cnt);
  
  return 0;
}

void Merge(int *A, int left, int mid, int right) {
  int n1 = 0, n2 = 0, i = 0, j = 0, k = 0;
  int *L, *R;
 

  n1 = mid - left;
  n2 = right - mid;

  L = (int *)malloc(sizeof(int) * (n1 + 1));
  R = (int *)malloc(sizeof(int) * (n2 + 1)); 
  
  for(i = 0 ; i < n1 ; i++) {
    L[i] = A[left + i];
  }

  for(i = 0 ; i < n2 ; i++) {
    R[i] = A[mid + i];
  }

  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0;
  j = 0;

  for(k = left ; k < right ; k++) {
    cnt++;
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    }
    else {
      A[k] = R[j];
      j++;
    }
  }
  free(L);
  free(R);

}


void mergeSort(int *A, int left, int right) {
  
  int mid = 0;

  if((left+1) < right) {
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    Merge(A, left, mid, right);
  }
}

