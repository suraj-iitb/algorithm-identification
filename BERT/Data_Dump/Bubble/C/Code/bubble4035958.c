#include<stdio.h>

int main(){
  int j,i,count=0,N,A[100],l=1,k;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  /*for(i=0;i<N;i++){
    printf("%d ",A[i]);
    }*/
  for(j=0;j<N;j++){
    for(i=N-1;i>=l;i--){
      if(A[i]<A[i-1]){
	k=A[i];
	A[i]=A[i-1];
	A[i-1]=k;
	count++;
      }
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1)printf(" ");
    else if(i==N-1)printf("\n");
  }
  printf("%d\n",count);
  return 0;
}

