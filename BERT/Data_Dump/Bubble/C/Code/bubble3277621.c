#include<stdio.h>
#define MAX 100

int main(){
  int A[MAX];
  int i,N,swap,flag,count = 0;

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  flag = 1;
  while(flag){
    flag = 0;
    for(i=N-1; i>=1; i--){
      if(A[i] < A[i-1]){
	swap = A[i];
	A[i] = A[i-1];
	A[i-1] = swap;
	count++;
	flag = 1;
      }
    }
  }

  for(i=0; i<N; i++){
    printf("%d",A[i]);
    if(i==N-1) break;
    printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

