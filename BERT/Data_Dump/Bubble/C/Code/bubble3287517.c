#include<stdio.h>
int main(){
  int i,j,N,count=0,temp,flag=1;
  int A[100];
    scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	temp=A[j-1];
	A[j-1]=A[j];
	A[j]=temp;
	count++;
	flag=1;
      }
    }
  }
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

