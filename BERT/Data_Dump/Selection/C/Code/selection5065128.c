#include <stdio.h>

int main(){
  int A[100];
  int i,j;
  int cnt = 0;
  int N;
  int minj,a;

  scanf("%d",&N);

  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0 ; i < N ; i++){
    minj = i;
    for(j = i ; j < N ; j++){
      if(A[j] < A[minj]){
        minj = j;
      }
    }
    a = A[i];
    A[i] = A[minj];
    A[minj] = a;
    if(i != minj) cnt++;
  }

  for(i = 0 ; i < N ; i++){
    printf("%d",A[i]);
    if(i != N-1) printf(" ");
  }

  printf("\n");

  printf("%d\n",cnt);

  return 0;
}
