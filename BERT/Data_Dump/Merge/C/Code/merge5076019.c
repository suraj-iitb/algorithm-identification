#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 5000000
#define INFTY 1000000001

int L[MAX/2+2], R[MAX/2+2], count, S[MAX];

void merge(int S[], int left, int mid, int right){
  int n1, n2, j=0, k;
  n1 = mid - left;
  n2 = right - mid;
  for(int i=0; i<n1; i++) L[i]=S[left+i];
  for(int i=0; i<n2; i++) R[i]=S[mid+i];
  L[n1] = INFTY;
  R[n2] = INFTY;
  int i=0;
  for(k=left; k<right; k++){
    count++;
    if(L[i]<=R[j]) S[k] = L[i++];
    else S[k] = R[j++];
  }
}

void mergeSort(int S[], int left, int right){
  int mid;
  if(left+1<right){
    mid = (left + right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}

int main(){
  int n, i, j;

  scanf("%d", &n);
  for(i=0; i<n; i++) scanf("%d", &S[i]);

  mergeSort(S, 0, n);

  for(j=0; j<n; j++){
    if(j!=0) printf(" ");
    printf("%d", S[j]);
  }
  printf("\n");

  printf("%d\n", count);

  return 0;
}
