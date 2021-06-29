#include<stdio.h>

int selectionSort(int A[], int N){
  int i, j, sw = 0, t, minj;

  for (i=0; i<N; i++){
    minj = i;
    for (j=i+1; j<N; j++){
      if (A[j] < A[minj]) minj = j;
    }
    if (minj != i){
      t = A[i];
      A[i] = A[minj];
      A[minj] = t;
      sw++;
    }
  }
  return sw;
}

int main(){
  int i, N, sw;
  int A[100];

  scanf("%d", &N);
  for (i=0; i<N; i++){
    scanf("%d", &A[i]);
  }

  sw = selectionSort(A, N);

  for (i=0; i<N; i++){
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n", sw);

  return 0;
}

