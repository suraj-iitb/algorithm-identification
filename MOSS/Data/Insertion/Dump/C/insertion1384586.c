#include <stdio.h>


void printArray(int A[], int N) {
  int i;

  printf("%d", A[0]);
  for(i=1; i<N; i++)
    printf(" %d", A[i]);
  putchar('\n');

}


void insertionSort(int A[], int N) {
  int i;

  printArray(A, N);
    
  for(i=1; i<N; i++) {
    int v = A[i];
    int j = i-1;

    while (j>=0 && A[j] > v) {
      A[j+1] = A[j];
      j--;
    }
    A[j+1] = v;
    printArray(A, N);
  }
 
}

int main(int argc, char *argv[]) {
  int N;
  int A[1000];
  int i;
  
  scanf("%d", &N);

  for (i=0; i<N; i++)
    scanf("%d", &A[i]);
  
  insertionSort(A,N);

  return 0;

}
