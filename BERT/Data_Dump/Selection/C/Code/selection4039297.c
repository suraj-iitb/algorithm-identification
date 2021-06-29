#include <stdio.h>
#define M 100

int selectionSort(int A[], int N){
  int i, j, k, sw = 0, a;
  for(i = 0; i < N - 1; i++){
    a = i;
    for(j = i; j < N; j++){
      if(A[j] < A[a]) a = j;}
    k = A[i];
    A[i] = A[a];
    A[a] = k;
    if(i != a)sw += 1;}
  return sw;
}
    

int main(){
  int A[M], i, N, sw;

  scanf("%d", &N);
  for(i = 0; i < N; i++)scanf("%d", &A[i]);
  sw = selectionSort(A, N);

  for(i = 0; i < N; i++){
     if(i == 0)printf("%d", A[i]);
    else if(i > 0){printf(" ");
      printf("%d", A[i]);}
    else break;}

  printf("\n");
  printf("%d\n", sw);
  return 0;
}

