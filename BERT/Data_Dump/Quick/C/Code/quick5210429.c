#include<stdio.h>
#define MAX 100001
#define SENTINEL 2000000001

struct Card{
  char s;
  int value;
};

struct Card L[MAX/2+2], R[MAX/2+2];

void merge(struct Card A[], int n, int left, int mid, int right){
  int w, i, j, k;
  int n1 = mid - left;
  int n2 = right - mid;
  for ( i = 0; i < n1; i++ ) L[i] = A[left + i];
  for ( i = 0; i < n2; i++ ) R[i] = A[mid + i];
  for(w=0;w<9;w++)
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

void mergeSort(struct Card A[], int n, int left, int right ){
  int mid;
  if ( left+1 < right ){
    mid = (left + right)/2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int partition(struct Card A[], int n, int p, int r){
  int i, j;
  struct Card t, x;
  x = A[r];
  i = p - 1;
  for ( j = p; j < r; j++ ){
    if ( A[j].value <= x.value ){
      i++;
      t = A[i]; A[i] = A[j]; A[j] = t;
    }
  }
  t = A[i+1]; A[i+1] = A[r]; A[r] = t;
  return i+1;
}

void quickSort(struct Card A[], int n, int p, int r){
  int q;
  if ( p < r ){
    q = partition(A, n, p, r);
    quickSort(A, n, p, q - 1);
    quickSort(A, n, q + 1, r);
  }
}

int main(){
  int n, i,j, v ,k, w;
  struct Card A[MAX], B[MAX];
  char S[10];
  int stable = 1;
  scanf("%d", &n);
 

  for ( i = 0; i < n; i++ ) {
    scanf("%s %d", S, &v);
    A[i].s = B[i].s = S[0];
    A[i].value = B[i].value = v;
  }
  for(j=0;j<9;j++)

  mergeSort(A, n, 0, n);
  quickSort(B, n, 0, n-1);

  for ( i = 0; i < n; i++ ){
    if ( A[i].s != B[i].s )
    stable = 0;
      }
 if ( stable == 1 )
    printf("Stable\n");
  else
    printf("Not stable\n");
  for ( i = 0; i < n; i++ ) {
    printf("%c %d\n", B[i].s, B[i].value);
  }
}










