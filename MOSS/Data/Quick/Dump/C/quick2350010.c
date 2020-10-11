#include <stdio.h>
#define MAX 100000

/* Struct Declaration */
typedef struct card {
  char p;
  int num;
}Card;

/* Prototype Declaration */
int partition(Card *, int, int);
void quickSort(Card *, int, int);
void merge(Card *, int, int, int);
void mergeSort(Card *, int, int);

/* Global Variable */
Card L[(MAX/2)+1], R[(MAX/2)+1]; 
int n;

int main() {
  int i, flag = 0;
  char picture[2];
  Card A[MAX], B[MAX];

  //Input and Copy
  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) {
    scanf("%s %d", picture, &A[i].num);
    A[i].p = picture[0];
    B[i].p = picture[0];
    B[i].num = A[i].num;
  }

  //Sort
  quickSort(A, 0, n - 1);
  mergeSort(B, 0, n);

  //Compare
  for ( i = 0; i < n; i++ ) {
    if ( A[i].p != B[i].p ) flag = 1;
  }

  //Output
  for ( i = 0; i < n; i++ ) {
    if ( flag == 1) {
      printf("Not stable\n");
      flag = -1;
    }else if ( flag == 0 ) {
      printf("Stable\n");
      flag = -1;
    }

    printf("%c %d\n", A[i].p, A[i].num);
  }

  return 0;
}

/* Partition */
int partition(Card *A, int p, int r) {
  Card x, temp;
  int i, j;

  x = A[r];
  i = p - 1;

  for ( j = p; j < r; j++ ) {
    if ( A[j].num <= x.num ) {
      i++;
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  }
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;

  return i + 1;
}

/* Quick Sort */
void quickSort(Card *A, int p, int r) {
  int q;
  if ( p < r ) {
    q = partition(A, p, r);
    quickSort(A, p, q - 1);
    quickSort(A, q + 1, r);
  }
}

/* Merge */
void merge(Card *B, int left, int mid, int right){
  int n1, n2;
  int i, j, k;

  n1 = mid - left;
  n2 = right - mid;

  for ( i = 0; i < n1; i++ ) L[i] = B[i+left];
  for ( i = 0; i < n2; i++ ) R[i] = B[i+mid];

  L[n1].num = 1000000500;
  R[n2].num = 1000000500;

  i = 0;
  j = 0;

  for ( k = left; k < right; k++ ) {
    if ( L[i].num <= R[j].num ) {
      B[k] = L[i];
      i++;
    }else {
      B[k] = R[j];
      j++;
    }
  }

}

/* Merge Sort */
void mergeSort(Card *B, int left, int right) {
  int mid;
  
  if ( left + 1 < right ) {
    mid = (left + right) / 2;
    mergeSort(B, left, mid);
    mergeSort(B, mid, right);
    merge(B, left, mid ,right);
  }
}
