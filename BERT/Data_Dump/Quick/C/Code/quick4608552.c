#include <stdio.h>
#include <string.h>

#define MAX 100000
#define SENTINEL 1000000000

typedef struct{
  int n;
  char c;
}Card;

int partition(Card *A, int p, int r){
  int i, j;
  int x;
  Card t;
  x = A[r].n;
  i = p-1;
  for(j=p; j<r; j++){
    if (A[j].n <= x) {
      i++;
      t = A[i]; A[i] = A[j]; A[j] = t;
    }
  }
  t = A[i+1]; A[i+1] = A[r]; A[r] = t;
  return i+1;
}

void quickSort(Card *A, int p, int r){
  int q;
  if (p<r) {
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}

void merge(Card *B, int left, int mid, int right){
  int i, j, k;
  int n1 = mid - left, n2 = right - mid;
  Card L[n1+1],R[n2+1];

  for(i = 0 ; i < n1 ; i++){
    L[i].c = B[left + i].c;
    L[i].n = B[left + i].n;
  }
  for(i = 0 ; i < n2 ; i++){
    R[i].c = B[mid + i].c;
    R[i].n = B[mid + i].n;
  }
  L[n1] = R[n2] = (Card){SENTINEL, '#'};
  for(i = 0,j = 0,k = left ; k < right ; k++){
    if(L[i].n <= R[j].n){
      B[k] = L[i++];
    }else{
      B[k] = R[j++];
    }
  }
}

void mergeSort(Card *B, int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(B, left, mid);
    mergeSort(B, mid, right);
    merge(B, left, mid, right);
  }
}

int isStable(Card *A, Card *B, int n){
  int i, j;
  int isStable = 1;
  for(i = 0 ; i < n ; i++){
    if(A[i].c != B[i].c || A[i].n != B[i].n){
      isStable = 0;
      break;
    }
  }
  return isStable;
}

int main(int argc, char const *argv[]) {
  Card A[MAX], B[MAX];
  int i, n;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    getchar();
    scanf("%c%d", &A[i].c, &A[i].n);
    B[i].c = A[i].c;
    B[i].n = A[i].n;
  }
  quickSort(A, 0, n-1);
  mergeSort(B, 0, n);
  printf("%s\n", (isStable(A, B, n)? "Stable" : "Not stable"));
  for(i=0; i<n; i++){
    printf("%c %d\n", A[i].c, A[i].n);
  }
  return 0;
}

