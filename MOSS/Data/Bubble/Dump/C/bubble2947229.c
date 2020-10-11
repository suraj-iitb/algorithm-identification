#include <stdio.h>
int main(){
  int A[100];
  int i,j,N,tmp,cnt = 0;
  int flag = 1;

  while(1){
    scanf("%d",&N);
    if(1 <= N && N <= 100){
      break;
    }
  }

  for(i = 0;i < N;i++){
    scanf("%d",&A[i]);
  }
  
  while(flag){
    flag = 0;
    for(j = N-1;j>=1;j--){
      if(A[j] < A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	flag = 1;
	cnt++;
      }
    }
  }
  
  for(i = 0;i < N;i++){
    if(i != N-1){
      printf("%d ",A[i]);
    }
    else printf("%d\n",A[i]);
  }
  printf("%d\n",cnt);
 
  return 0;
}

