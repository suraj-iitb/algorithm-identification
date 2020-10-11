#include<stdio.h>

int main(){
  int i,j,num,n=0,N,minj,flag,A[100];

  scanf("%d",&N);
  for(i = 0; i < N;i++) scanf("%d",&A[i]);

  for(i = 0 ; i < N-1;i++){
    flag =0;
    minj = i;
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
	minj = j;
	flag =1;
      }
    }
    num = A[minj];
    A[minj] = A[i];
    A[i] = num;
    if(flag == 1)n++;
      
  }
   for(i = 0; i < N-1; i++)   printf("%d ",A[i]);
    printf("%d",A[N-1]);
  printf("\n%d\n",n);

}

