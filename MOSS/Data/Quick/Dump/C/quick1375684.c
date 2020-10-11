#include <stdio.h>
#define MAX 100000

typedef struct {
  char design;
  int number;
} CARD;

int Partition(CARD*, int, int);
void Swap(CARD*, CARD*);
void QuickSort(CARD*, int, int);
void merge(CARD*, int, int, int);
void mergeSort(CARD*, int, int);

main(){
  int n, i, j, x;
  char c;
  CARD A[MAX], B[MAX];

  scanf("%d", &n);

  for( i = 0; i < n; i++){
    scanf(" %c%c%d", &A[i].design, &c, &A[i].number);
    B[i] = A[i];
  }

  QuickSort(A, 0, n-1);

  mergeSort(B, 0, n);

  for( i = 0; i < n; i++){
    if( A[i].number == B[i].number && A[i].design != B[i].design ){
      printf("Not stable\n");
      break;
    }
    if( i == n-1 ) printf("Stable\n");
  }

  for( i = 0; i < n; i++){
    printf("%c %d\n", A[i].design, A[i].number);
  }

  return 0;

}



void QuickSort(CARD *A, int p, int r){
  int q;

  if( p < r ){
    q = Partition(A, p, r);
    QuickSort(A, p, q-1);
    QuickSort(A, q+1, r);
  }

}


int Partition(CARD *A, int p, int r){
  int x, i, j, k;

  x = A[r].number;
  i = p-1;

  for( j = p; j < r; j++){

    if( A[j].number <= x ){
      i = i+1;
      Swap(&A[i], &A[j]);
    }

  }

  Swap(&A[i+1], &A[r]);

  return i+1;

}



void Swap(CARD *A, CARD *B){
  CARD x;

  x = *A;
  *A = *B;
  *B = x;

}


void merge(CARD *seq, int left, int mid, int right){
  int n1, n2, i, j, k;
  CARD L[MAX], R[MAX];

  n1 = mid - left;
  n2 = right - mid;

  for( i = 0; i < n1; i++){
    L[i] = seq[left+i];
  }

  for( i = 0; i < n2; i++){
    R[i] = seq[mid+i];
  }

  L[n1].number = 1000000000;
  R[n2].number = 1000000000;

  i = 0;
  j = 0;

  for( k = left; k < right; k++){

    if( L[i].number <= R[j].number ){
      seq[k] = L[i];
      i = i + 1;
    }

    else{
      seq[k] = R[j];
      j = j + 1;
    }

  }

}


void mergeSort(CARD *seq, int left, int right){
  int mid;

  if( left+1 < right ){

    mid = ( left + right ) / 2;

    mergeSort(seq, left, mid);

    mergeSort(seq, mid, right);

    merge(seq, left, mid, right);

  }

}
