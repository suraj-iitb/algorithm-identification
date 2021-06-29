#include <stdio.h>
#include <stdlib.h>

#define MAX 10*10*10*10*10*10*10*10*10

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int S[500000];
int count=0;

int main(){
  int n, i, j;

  scanf("%d",&n);
  if(n > 500000) exit(1);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
    if(S[i] < 0 || MAX < S[i]) exit(2);
  }

  mergeSort(S,0,n);

  for(j=0; j<n; j++){
    printf("%d", S[j]);
    if(j<n-1) printf(" ");
  }
  printf("\n%d\n", count);

  return 0;
}

void merge(int *A, int left, int mid, int right){
  int n1, n2, i, j, k;
  int L[500000], R[500000];

  n1=mid-left;
  n2=right-mid;
  for(i=0; i<n1; i++){
    L[i]=A[left+i];
  }
  for(j=0; j<n2; j++){
    R[j]=A[mid+j];
  }
  L[n1]=R[n2]=MAX;
  i=j=0;
  for(k=left; k<right; k++){
    if(L[i] <= R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    count++;
  }
}

void mergeSort(int *A, int left, int right){
  int mid;
  
  if(left+1 < right){
    mid=(left+right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

