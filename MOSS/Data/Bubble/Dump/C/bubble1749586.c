#include<stdio.h>

int main(){

  int A[100],i,j,min,N,flag=1,count=0;

  scanf("%d",&N);
  if(N>=1 && N<=100){
    for(i=0;i<N;i++){
      scanf("%d",&A[i]);
    }
    while(flag){
      flag=0;
      for(j=N-1;j>=1;j--){
	if(A[j]<A[j-1]){
	  min=A[j];
	  A[j]=A[j-1];
	  A[j-1]=min;
	  flag=1;
	  count++;
	}}}
    for(i=0;i<N;i++){
      if(i>0) printf(" ");
      printf("%d",A[i]);
    }
    printf("\n");
    printf("%d\n",count);
  }
  return 0;
}
