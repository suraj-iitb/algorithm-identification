#include<stdio.h>

int main(){
  int N,i,j,minj,temp,count=0;
  scanf("%d",&N);
  int A[N];

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N-1;i++){
    minj = i;
    for(j=i;j<=N-1;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
      temp = A[i];
      A[i] = A[minj];
      A[minj] = temp;
      if(i != minj){
      count = count + 1;
      }
    }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i != N-1){
      printf(" ");
    }
  }

  printf("\n");

  printf("%d\n",count);

  return 0;
}

      

