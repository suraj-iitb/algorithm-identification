#include <stdio.h>

int main(){
  int N,A[100],i,j,minj,tmp,count=0;
  scanf("%d",&N);

  if(1<=N && N<=100){
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }

    for(i=0;i<=N-1;i++){
      minj = i;
      for(j=i;j<=N-1;j++){
	if(A[j] < A[minj]){
	  minj = j;
	}
      }
      if(i!=minj){
	tmp = A[i];
	  A[i] = A[minj];
	  A[minj] = tmp;
	  count++;
      }
      
    }

    for(i=0;i<N-1;i++){
      printf("%d ",A[i]);
    }
    printf("%d\n", A[N-1]);
    printf("%d\n", count);
  }

  return 0;
}
	   

