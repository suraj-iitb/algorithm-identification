#include <stdio.h>


int main(){
  int N,A[100],i=0,j,flag,tmp;

    scanf("%d",&N);
  if(1<=N && N<=100){
    for(j=0;j<N;j++){
      scanf("%d",&A[j]);
    }

    flag = 1;
    
    while(flag != 0){
      flag = 0;
      for(j=N-1;j>=1;j--){
	if(A[j] < A[j-1]){
	  tmp = A[j];
	  A[j] = A[j-1];
	  A[j-1] = tmp;
	  flag = 1;
	  i++;
	}
      }
    }
    for(j=0;j<N-1;j++){
      printf("%d ",A[j]);
    }
    printf("%d\n",A[N-1]);
    printf("%d\n",i);
  }

  return 0;
}

