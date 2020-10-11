#include<stdio.h>

int main(){
  int i,j,A[100],N,count=0,temp=0;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j] < A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	count++;
      }
      
    }
  }
  
  for(i=0;i<N;i++){
    if(i > 0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

