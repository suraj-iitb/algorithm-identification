#include <stdio.h>
#include <stdlib.h>
int main(){
  int N,i,j,flag=1,temp,count=0,*A;

  scanf("%d",&N);
  A = (int *)malloc(sizeof(int) * N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  while(flag==1){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);

  return 0;
}

