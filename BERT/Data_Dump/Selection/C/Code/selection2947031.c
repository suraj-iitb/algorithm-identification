#include<stdio.h>

int selectionSort(int A[], int N){
  int i, j, t, sel = 0, minj;
  for(i = 0; i < N-1 ; i++){
    minj = i;
    for( j = i ; j < N ; j++){
      if( A[j] < A[minj] ) minj = j;
    }
    t = A[i];
    A[i] = A[minj];
    A[minj] = t;
    if( i != minj ) sel++;
  }
  return sel;
}

int main(){
  int i, N, sel;
  int A[100];
  scanf("%d", &N);
  for( i = 0 ; i < N; i++){
    scanf("%d", &A[i]);
  }

  sel = selectionSort(A, N);

  for(i = 0 ; i < N ; i++){
    if( i>0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
  printf("%d\n",sel);
}

