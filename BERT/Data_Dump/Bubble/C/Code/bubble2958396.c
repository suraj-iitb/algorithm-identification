#include<stdio.h>

int main(){
  int j,k,N,flag,count=0;
  int eg;
  int A[100];

  scanf("%d",&N);
  if((N>100)&&(N<0)){
    printf("error\n");
  }
  for(j=0;j<N;j++){
    scanf("%d",&A[j]);
  }

  flag=1;
  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	eg=A[j];
	A[j]=A[j-1];
	A[j-1]=eg;
	flag=1;
	count++;
	
      }
    }
  }

  for(k=0;k<N;k++){
    if(k>0){
      printf(" ");
    }
    printf("%d",A[k]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

