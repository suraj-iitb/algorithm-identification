#include <stdio.h>

int main(void){
  int N, A[100], i, j, c, s;
  c = 0;
 
  scanf("%d", &N);
 
  for(i = 0;i < N;i++) scanf("%d", &A[i]);
 
  for(i = 1;i <= N - 1;i++){
    for(j = 0;j < N - i;j++){
      if(A[j] > A[j+1]){
        s = A[j];
        A[j] = A[j+1];
        A[j+1] = s;
        c++;
      }
    }
  }
 
  for(i = 0;i < N;i++) {
    if(i != 0) printf(" ");
    printf("%d", A[i]);
  }

  printf("\n");
 
  printf("%d\n", c);
 
  return 0;
}
