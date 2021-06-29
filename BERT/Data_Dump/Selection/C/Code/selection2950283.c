#include <stdio.h>

int main(){
  int i,j,minj,A[100],N,tmp,cnt=0;
  
  while(1){
    scanf("%d",&N);
    if(N>=1 && N<= 100){
      break;
    }  
  }
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i = 0;i < N;i++){
    minj = i;
    for(j = i;j < N;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
      if(minj != i){
	tmp = A[i];
	A[i] = A[minj];
	A[minj] = tmp;
	cnt++;
      }
  }

  for(i = 0;i < N;i++){
    if(i < N-1){
      printf("%d ",A[i]);
    }
    else printf("%d\n",A[i]);
  }
  printf("%d\n",cnt);
  
  return 0;
}

