#include<stdio.h>

int main(){
  int a,A[101],N,j,i,man;

  scanf("%d",&N);
    int cnt = 0;
  for(a=0;a < N;a++){
    scanf("%d",&A[a]);
  }
  for(a=0;a < N; a++){
  for(j = N-1;j > a;j--){
    if(A[j] < A[j-1]){
      man = A[j];
      A[j] = A[j-1];
      A[j-1] = man;
      cnt++;
    }
  }
  }
    for(a=0;a < N; a++){
    if(a==N-1)
    printf("%d\n",A[a]);
  else
    printf("%d ",A[a]);
    }

  printf("%d\n",cnt);

  return 0;
}

