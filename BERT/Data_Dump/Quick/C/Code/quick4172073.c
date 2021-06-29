#include<stdio.h>
#define MAX 100959
#define SENTINEL 1000000000
#define TRUE 1
#define FAULSE 0
#define PP 100

typedef struct {
  char suit;
  int value;
} Card;

 Card L[MAX/2+2];
 Card R[MAX/2+2];
 
 void mergeSort( Card A[], int n, int left, int right );
 void quickSort( Card A[], int n, int p, int r);
 int partition( Card A[], int n, int p, int r);
 void merge( Card A[], int n, int left, int mid, int right) ;
 
 int main(){
  int n, i, v;
   Card A[MAX], B[MAX];
  char CC[10];
  int stable = 1;
  scanf("%d", &n);

  for ( i = 0; i < n; i++ ) {
    scanf("%s %d", CC, &v);
    A[i].suit = B[i].suit = CC[0];
    A[i].value = B[i].value = v;
  }
  
  

  mergeSort(A, n, 0, n);
  quickSort(B, n, 0, n-1);

  for ( i = 0; i < n; i++ ){
    if ( A[i].suit != B[i].suit ) stable = FAULSE;
  }

  if ( stable == TRUE ) {
  	printf("Stable\n");
  } else {
  	printf("Not stable\n");
  }
  
  int z;
  
  for ( i = 0; i < n; i++ ) {
    printf("%c %d\n", B[i].suit, B[i].value);
  }
}

 
void mergeSort( Card A[], int n, int left, int right ) {
  int mid;
  if ( left+1 < right ){
    mid = (left + right)/2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

void quickSort( Card A[], int n, int p, int r) {
  int q;
  if ( r > p ){
    q = partition(A, n, p, r);
    quickSort(A, n, q + 1, r);
    quickSort(A, n, p, q - 1);
  }
}

int partition( Card A[], int n, int p, int r) {
  int i, j;
   Card t, x;
  x = A[r];
  i = p - 1;
  for ( j = p; j < r; j++ ){
    if ( A[j].value <= x.value ){
      i++;
      t = A[i]; A[i] = A[j]; A[j] = t;
    }
  }
  t = A[i+1]; 
  A[i+1] = A[r]; 
  A[r] = t;
  return i +1;
}

void merge( Card A[], int n, int left, int mid, int right) {
  int i, j, k, n1, n2;
   n1 = mid - left;
   n2 = right - mid;
  for ( i = 0; i < n2; i++ ) R[i] = A[mid + i];
  for ( i = 0; i < n1; i++ ) L[i] = A[left + i];
  L[n1].value = R[n2].value = SENTINEL;
  i = j = 0;
  for ( k = left; k < right; k++ ){
    if ( L[i].value <= R[j].value ){
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}


