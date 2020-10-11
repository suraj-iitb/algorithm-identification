#include <stdio.h>

/* Macro Definition */
#define MAX 500000

/* Prototype Declaration */
void marge(int, int, int);
void margeSort(int, int);

/* Grobal Variable */
int S[MAX], L[(MAX/2) + 1], R[(MAX/2) + 1], n, count = 0;

int main() {
  int i;

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ) scanf("%d", &S[i]);

  margeSort(0, n);

  for ( i = 0; i < n; i++ ) {
    printf("%d", S[i]);
    if(i < n - 1) printf(" ");
  }
  printf("\n%d\n", count);


  return 0;
}

void marge(int left, int mid, int right) {
  int i, j = 0, k, n1, n2;
  n1 = mid - left;
  n2 = right - mid;

  for ( i = 0; i < n1; i++ ) L[i] = S[i+left];
  for ( i = 0; i < n2; i++ ) R[i] = S[i+mid];

  L[n1] = 1000000050;
  R[n2] = 1000000050;

  i = 0;

  for ( k = left; k < right; k++ ) {
    count++;
    if ( L[i] <= R[j] ) {
      S[k] = L[i];
      i++;
    }else {
      S[k] = R[j];
      j++;
    }
  }

}

void margeSort(int left, int right) {
  int mid;
  
  if( left + 1 < right ) {
    mid = (left + right) / 2;
    margeSort(left, mid);
    margeSort(mid, right);
    marge(left, mid, right);
  }

}
