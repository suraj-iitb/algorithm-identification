#include <stdio.h>
int main(){
  int A[100], N, i, j, swap, mini, count = 0, han;
  scanf("%d", &N);
  for(i = 0; i < N; i++){
    scanf("%d", &A[i]);
  }
  for(i = 0; i < N - 1; i++){
    han = 0;
    mini = i;
    for(j = i; j < N; j++){
      if(A[j] < A[mini]){
	mini = j;
	han = 1;
      }
    }
    if(han == 1){ 
    swap = A[i];
    A[i] = A[mini];
    A[mini] = swap;
    count++;
    }
  }
    for(i = 0; i < N; i++){
      printf("%d", A[i]);
      if(i < (N - 1))printf(" ");
  }
    printf("\n%d\n", count);

  return 0;
}
