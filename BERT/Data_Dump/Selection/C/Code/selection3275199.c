#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *, int);

int main(){
  int A[100];
  int i, N;

  scanf("%d",&N);
  if(N < 1 || 100 < N) exit(1);

  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || 100 < A[i]) exit(2);
  }

  selectionSort(A, N);

  return 0;
}

void selectionSort(int *A, int N){
  int i, j, k, minj, tem, num=0;

  for(i=0; i<=N-1; i++){
    minj=i;
    for(j=i; j<=N-1; j++){
      if(A[j] < A[minj]) minj=j;
    }
    tem=A[i];
    A[i]=A[minj];
    A[minj]=tem;
    if(i != minj) num++;
  }

  for(k=0; k<N; k++){
    if(k) printf(" ");
    printf("%d", A[k]);
  }
  printf("\n%d\n", num);
}


  

