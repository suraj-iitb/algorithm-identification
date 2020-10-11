#include <stdio.h>

int main(){

  int i,j,k,N,A[100],count=0;

  int minj;

  scanf("%d",&N);

  for(i=0;i<N;i++){
  scanf("%d",&A[i]);
  }
  
  for(i=0;i<=N-1;i++){
    count++;
    minj=i;

    for(j=i;j<=N-1;j++){
      
      if(A[j]<A[minj]){
	minj=j;
      }
    }

    if(A[minj]==A[i]){
      count--;
    }
	k=A[i];
	A[i]=A[minj];
	A[minj]=k;
	
      
	
  }

  for(k=0;k<N;k++){
    if(k!=0){
      printf(" ");
    }
    printf("%d",A[k]);
  }
  printf("\n");

  printf("%d\n",count);
    return 0;
  }
		    

