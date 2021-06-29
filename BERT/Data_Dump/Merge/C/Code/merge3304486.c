#include<stdio.h>

#define N 500000
#define INFTY 2000000000

int L[N / 2 + 2];
int R[N / 2 + 2];
int count = 0;

void merge(int*,int,int,int,int);
void mergeSort(int*,int,int,int);


int main() {
  int S[N];
  int i,x;

  scanf("%d",&x);
  for(i = 0; i < x; i++) {
    scanf("%d",&S[i]);
  }

  mergeSort(S,x,0,x);

  for(i = 0; i < x; i++) {
    printf("%d",S[i]);
    if(i != x - 1) {
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

void merge(int A[],int n,int left,int mid,int right) {
  int i,j,k,n1,n2;
  
  n1 = mid - left;
  n2 = right - mid;

  for( i = 0; i < n1; i++) {
    L[i] = A[left + i];
  }
  for( i = 0; i < n2; i++) {
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left; k < right; k++) {
    count++;
    if(L[i] <= R[j]) {
      A[k] = L[i];
      i =  i + 1;
    }else{ 
      A[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int A[],int n,int left,int right) {
  int mid;
  if(left + 1 < right) {
    mid = (left + right) / 2;
    mergeSort(A,n,left,mid);
    mergeSort(A,n,mid,right);
    merge(A,n,left, mid, right);
  }
}

