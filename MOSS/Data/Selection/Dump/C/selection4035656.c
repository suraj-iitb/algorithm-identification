#include <stdio.h>

int main(){
  int i,cnt = 0, N, A[100], tmp, j, minj;

  scanf("%d",&N);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; i < N-1; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    tmp = A[i];
    A[i] = A[minj];
    A[minj] = tmp;
    if(i != minj)cnt++;
  }

  for(i = 0; i < N; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}


