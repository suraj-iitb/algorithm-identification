
#include <stdio.h>
#include <stdlib.h>

#define NMIN 1
#define NMAX 100
#define AMIN 0
#define AMAX 1000

void insertionSort(int*, int);

int main() {
  int N;
  int *A;
  int i; // counter
  
  scanf("%d", &N);
  if(N<NMIN||NMAX<N) { // if N is out of range
    fprintf(stderr, "1<=N<=100\n"); // output error statement
    exit(8);
  }

  A = (int*)malloc(sizeof(int)*N);
  for(i=0; i<=N-1; i++) {
    scanf("%d", &A[i]);
    if(A[i]<AMIN||AMAX<A[i]) { // if A is out of range
      fprintf(stderr, "0<=A[i]<=1000\n"); // output error statement
      exit(8);
    }
  }
  
  insertionSort(A, N);

  free(A);
  
  return 0;
}

void insertionSort(int *A, int N) {
  int i, j, k; // counter
  int v; // key

  for(k=0; k<=N-1; k++) { // output what was input
    printf("%d", A[k]);
    if(k!=N-1)
      printf(" ");
  }
  printf("\n");
  
  for(i=1; i<=N-1; i++) { // insertion sort
    v = A[i];
    j = i - 1;
    while(0<=j&&v<A[j]) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    
    for(k=0; k<=N-1; k++) { // output the intermediate sequence
      printf("%d", A[k]);
      if(k!=N-1)
	printf(" ");
    }
    printf("\n");
  }
}

