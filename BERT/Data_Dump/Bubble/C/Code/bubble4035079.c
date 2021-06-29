#include <stdio.h>

int main(){
  int i,cnt = 0, flg = 1, N, A[100], tmp, j;

  scanf("%d",&N);

  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }

  for(i = 0; flg == 1; i++){
    flg = 0;
    for(j = N-1; j >= i+1; j--){
      if(A[j] < A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	flg = 1;
	cnt++;
      }
    }
  }

  for(i = 0; i < N; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);
  
  return 0;
}

