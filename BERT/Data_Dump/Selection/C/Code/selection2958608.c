#include <stdio.h>

int main(){

  int i,minj,j,count=0,N,A[100],tmp;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j] < A[minj]) minj=j;
			   
    }
    if(minj!=i){
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
      count++;
    }
  }
  for(j=0;j<N;j++){
    if(j>0) printf(" ");
    printf("%d",A[j]);
  }
  printf("\n");
  printf("%d\n",count);

  
}

