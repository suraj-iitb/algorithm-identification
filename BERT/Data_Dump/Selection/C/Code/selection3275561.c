#include <stdio.h>

int main(){
  int A[100], N, i, j, x, ch, cnt = 0;
  scanf("%d",&N);
  for(i = 0; i < N; i++)scanf("%d",&A[i]);

  for(i = 0; i < N-1; i++){
    x = i;
    for(j = i; j < N; j++){
      if(A[j] < A[x]) x = j;
    }
    ch = A[i];
    A[i] = A[x];
    A[x] = ch;
    if(i != x)cnt++;
  }

  for(i = 0; i < N; i++){
    printf("%d",A[i]);
    if(i < N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}

