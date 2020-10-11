#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,j,minj,N,n,A[100],sum = 0,flag = 0;

  scanf("%d",&N);
  if(N < 1 || N > 100) exit(1);

  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || A[i] > 100) exit(2);
  }

  for(i = 0;i < N;i++){
    minj = i;
    flag = 0;
    for(j = i;j < N;j++){
      if(A[j] < A[minj]){
	minj = j;
	flag = 1;
      }
    }
    n = A[i];
    A[i] = A[minj];
    A[minj] = n;
    sum += flag;
  }

  for(i = 0;i < N;i++){
    if(i == 0) printf("%d",A[i]);
    else printf(" %d",A[i]);
  }

  printf("\n%d\n",sum);

  return 0;
}

