#include<stdio.h>
#include<stdlib.h>
#define mymalloc(p, n) {p = malloc((n)*sizeof(*p)); if((p) == NULL){printf("not enough memory.\n"); exit(1);}}

void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main() {
  int n;
  int *A;
  int i, j, k, key;

  scanf("%d", &n);
  mymalloc(A, n);
  for(i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

trace(A, n);

  for(i = 1; i < n; i++) {
    key = A[i];
    j = i;
    while(key < A[j-1] && j > 0) {
      A[j] = A[j-1];
      A[j-1] = key;
      j--;
    }
trace(A, n);
  }

  return 0;
}
