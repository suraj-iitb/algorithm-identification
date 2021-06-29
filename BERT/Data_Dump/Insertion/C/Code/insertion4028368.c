#include <stdio.h>

int insertionSort(int [1000], int N);

int main(void){
  int i, j, k, v, N;
  int A[1000];
  scanf("%d", &N);
  for (i=0; i<N; ++i)scanf("%d", &A[i]);
  insertionSort(A, N);
  return 0;
}

int insertionSort(int A[1000], int N){
  int i, j, v, k;
  for (k=0; k<N-1; ++k)printf("%d ", A[k]);
  printf("%d", A[N-1]);
  printf("\n");
  for (i=1; i<=N-1; ++i){
    v = A[i];
    j = i - 1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for (k=0; k<N-1; ++k)printf("%d ", A[k]);
    printf("%d", A[N-1]);
    printf("\n");
     
  }
}
