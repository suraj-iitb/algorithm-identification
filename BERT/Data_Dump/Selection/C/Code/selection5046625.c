#include<stdio.h>
#include<stdlib.h>
#define NMAX 100
#define NMIN 1

void selectionSort(int *, int);

int cnt=0;

int main(){
  int N, *A;
  int i;

  scanf("%d", &N);
  if(N<NMIN || N>NMAX) exit(1);

  A = (int *)malloc(N * sizeof(int));

  for(i=0;i<N;i++) scanf("%d", &A[i]);

  selectionSort(A, N);

  for(i=0;i<N;i++){
    printf("%d", A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n", cnt);
  free(A);

  return 0;
}

void selectionSort(int *A, int N){
  int i, j, minj, v;
  for(i=0;i<=N-1;i++){
    minj = i;
    for(j=i;j<=N-1;j++){
      if(A[j] < A[minj])
        minj = j;
    }
    v = A[minj];
    A[minj] = A[i];
    A[i] = v;
    if(i != minj) cnt++;
  }
}
