#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,n,N,A[100],flag = 1,sum = 0;

  scanf("%d",&N);
  if(N < 1 || N > 100) exit(1);

  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
    if(A[i] < 0 || A[i] > 100) exit(2);
  }

  while(flag){
    flag = 0;
    for(i = N - 1;i > 0;i--){
      if(A[i] < A[i - 1]){
	n = A[i];
	A[i] = A[i - 1];
	A[i - 1] = n;
	sum++;
	flag = 1;
      }
    }
  }
  
  for(i = 0;i < N;i++){
    if(i == 0) printf("%d",A[i]);
    else printf(" %d",A[i]);
  }

  printf("\n%d\n",sum);

  return 0;
}

