#include<stdio.h>

int main(){
  int i,N,j,n=0,num,A[100];

  scanf("%d",&N);
  for(i = 0; i < N; i++) scanf("%d",&A[i]);

  for(i = 0; i < N; i++){
    for(j = N - 1; j > i ; j--){
      if(A[j] < A[j-1]){
	num = A[j-1];
	A[j-1] = A[j];
	A[j] = num;
	n++;
      }
    }
  }
  for(i = 0; i < N-1; i++)   printf("%d ",A[i]);
    printf("%d",A[N-1]);
  printf("\n%d\n",n);
  
}

