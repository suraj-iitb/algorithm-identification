#include <stdio.h>

int main(){
  int A[100],N,i,j,tmp,flag=1,cnt=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  while(flag == 1){
    flag = 0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	flag = 1;
	cnt++;
      }
    }
  }

  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i+1 == N){
      printf("\n");
      break;
    }
    printf(" ");
  }
  printf("%d\n",cnt);
  
  return 0;
}

