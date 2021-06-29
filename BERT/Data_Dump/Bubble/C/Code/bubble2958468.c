#include <stdio.h>

int main(){

  int i,j,N,flag,A[100],count=0,tmp;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  flag=1;
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      
      if(A[j] < A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	flag=1;
	count++;
      }
      
    }
    
  }
  for(j=0;j<N;j++){
    if(j>0) printf(" ");
    printf("%d",A[j]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

