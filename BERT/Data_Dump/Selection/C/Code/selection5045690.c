#include <stdio.h>
int selectionSort(int *, int);
int main(){
  int N, i, count;
  scanf("%d", &N);
  int A[N];
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  count = selectionSort(A, N);
  for(i = 0; i < N; i++){
    printf("%d", A[i]);
    if(i < N - 1) printf(" ");
  }
  printf("\n");
  printf("%d\n", count);
  return 0;
}
int selectionSort(int A[], int n){
  int flag = 0, count = 0, i, j, k, minj;
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(i != minj){
    k = A[i];
    A[i] = A[minj];
    A[minj] = k;
    flag++;
    }
  }
  return flag;
}
