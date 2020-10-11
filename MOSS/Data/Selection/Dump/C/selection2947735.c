#include <stdio.h>
#include <stdlib.h>

int main(){
  int i,j,k;
  int minj,cnt = 0;
  int tmp;
  int N;
  int A[100];

  if(scanf("%d",&N) > 100)
    exit(1);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || A[i] > 100)
      exit(2);
  }

  for(i = 0; i < N; i++){
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
	minj = j;

      }
    }
    tmp = A[minj];
    A[minj] = A[i];
    A[i] = tmp;
    if(A[i] != A[minj])
      cnt++;
  }
  
  for(i = 0; i < N; i++){
    printf("%d",A[i]);
    if(i != N-1)
      printf(" ");
  }
  printf("\n%d\n",cnt);
  return 0;
}

