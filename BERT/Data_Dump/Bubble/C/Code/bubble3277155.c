#include <stdio.h>

int main(){
  int flag,j,k,count,swap,N;
  int A[100];

  count=0;

  scanf("%d",&N);
  for(j=0;j<N;j++){
    scanf("%d",&A[j]);
  }
  
  flag=1;
  while(flag==1){
    flag=0;  
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	  swap=A[j];
	  A[j]=A[j-1];
	  A[j-1]=swap;
	  flag=1;
	  count++;
      }
    }
  }
  printf("%d",A[0]);
  for(j=1;j<N;j++){
    printf("% d",A[j]);
  }
  printf("\n%d\n",count);

  return 0;
}

