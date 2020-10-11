#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100000
#define INFTY 1000000000

typedef struct{
  int n;
  char c;
}card;

int partition(card *, int, int);
void swap(card *, card *);
void quickSort(card *, int, int);
void merge(card *, int, int, int);
void mergeSort(card *, int, int);

int main(){
  int i, q, n;
  card A[MAX_N], S[MAX_N];

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf(" %c %d", &A[i].c, &A[i].n);
    S[i].c = A[i].c;
    S[i].n = A[i].n;
  }
  
  quickSort(A, 0, n-1);
  mergeSort(S, 0, n);

  for(i=0; i<n; i++){
    if(A[i].c != S[i].c){
      printf("Not stable\n");
      break;
    }else if(i == n-1){
      printf("Stable\n");
    }
  }

  for(i=0; i<n; i++){
    printf("%c %d\n", A[i].c ,A[i].n);
  }

  return 0;
}

void quickSort(card *A, int p, int r){
  int q;

  if(p < r){
    q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }

}

int partition(card *A, int p, int r){
  int i, j, x;

  x = A[r].n;
  i = p-1;

  for(j=p; j<r; j++){
    if(A[j].n <= x){
      i = i+1;
      swap(&A[i], &A[j]);
    }
  }
  swap(&A[i+1], &A[r]);

  return i+1;
}

void swap(card *a, card *b){
  card temp;

  temp.n = a->n;
  a->n = b->n;
  b->n = temp.n;

  temp.c = a->c;
  a->c = b->c;
  b->c = temp.c;

}

void merge(card *A, int left, int mid, int right){
  int i, j, k;
  int n1, n2;
  card L[mid - left + 1], R[right - mid + 1];

  n1 = mid - left;
  n2 = right - mid;

  for( i=0; i < n1; i++){
    L[i] = A[left + i];
  }

  for( i=0; i < n2; i++){
    R[i] = A[mid + i];
  }

  L[n1].n = INFTY;
  R[n2].n = INFTY;

  i = 0;
  j = 0;

  for( k = left; k < right; k++){
    if(L[i].n <= R[j].n){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }

}

void mergeSort(card *A, int left, int right){
  int mid;

  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }

}
