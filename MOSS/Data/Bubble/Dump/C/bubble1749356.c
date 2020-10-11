#include<stdio.h>
#include<stdlib.h>

int main(){
  int N,i,j,A[100],count=0,temp;

  scanf("%d",&N);
  if(N<1 || N>100){
    exit(1);
  }

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || A[i]>100){
      exit(8);
    }
  }
  
  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;

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
