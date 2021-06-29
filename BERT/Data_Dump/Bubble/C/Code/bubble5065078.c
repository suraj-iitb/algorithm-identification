#include <stdio.h>

int main(){
  int A[100];
  int i,j;
  int flag=1;
  int cnt = 0;
  int N;

  scanf("%d",&N);

  for(i = 0 ; i < N ; i++){
    scanf("%d",&A[i]);
  }

  while(flag == 1){
    flag = 0;
    for(j = N-1 ; j > 0 ; j--){
      if(A[j] < A[j-1]){
        flag = A[j];
        A[j] = A[j-1];
        A[j-1] = flag;
        flag = 1;
        cnt++;
      }
    }
  }

  for(i = 0 ; i < N ; i++){
    printf("%d",A[i]);
    if(i != N-1) printf(" ");
  }

  printf("\n");

  printf("%d\n",cnt);

  return 0;
}
