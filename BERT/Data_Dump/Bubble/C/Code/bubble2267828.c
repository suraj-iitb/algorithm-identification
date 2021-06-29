#include <stdio.h>

int main(){
  int flag,i,j,N,A[100],B[100],count=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  flag=1;

  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	B[j]=A[j-1];
	A[j-1]=A[j];
	A[j]=B[j];
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}
