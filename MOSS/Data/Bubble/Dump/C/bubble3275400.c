#include <stdio.h>

int main(){
  int N, A[100], i = 0, j, flag = 1, ch, cnt = 0;
  scanf("%d",&N);
  
  for(i = 0; i < N; i++)scanf("%d",&A[i]);
  i = 0;
  while(flag){
    flag = 0;
    for(j = N-1; j > i; j--){
      if(A[j] < A[j-1]){
	cnt++;
	ch = A[j];
	A[j] = A[j-1];
	A[j-1] = ch;
	flag = 1;
      }
    }
    i++;
  }
  for(j = 0; j < N; j++){
    printf("%d",A[j]);
    if(j < N-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",cnt);
  return 0;
}


