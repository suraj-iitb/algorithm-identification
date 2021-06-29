#include <stdio.h>
#include <stdlib.h>

#define MAX 2000001
#define VMAX 10001

void countingSort(int*, int, int*, int);

int main() {
  int i, al;
  int *arrayA, *arrayB;

  arrayA = malloc(sizeof(int)*MAX);
  arrayB = malloc(sizeof(int)*MAX);
  
  scanf("%d", &al);
  for(i=1 ; i <= al ; i++) { scanf("%d", &arrayA[i]); }

  countingSort(arrayA, al, arrayB, 10000);
  
  for(i=1 ; i <= al ; i++) {
    printf("%d", arrayB[i]);
    if(i != al) { printf(" "); }
  }
  printf("\n");
  
  return 0;
}

void countingSort(int *A, int al, int *B, int k) {
  int i, C[VMAX];
  
  for(i=0; i <= k ; i++) { C[i] = 0; }

  for(i=1; i <= al ; i++) { C[A[i]]++; }

  for(i=1; i <= k ; i++) { C[i] = C[i] + C[i-1]; }

  for(i=al; i >= 1 ; i--) {
    B[C[A[i]]] = A[i];
    C[A[i]]--;
  }
}


