#include<stdio.h>

int main(){

  int i,j,tmp,count=0,flag=1,N,A[101];

  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d",&A[i]);

  while(flag){

    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	tmp=A[j];
	A[j]=A[j-1];
	A[j-1]=tmp;
	count++;
	flag=1;
      }
    }
  }

    for(i=0;i<N-1;i++)
      printf("%d ",A[i]);

    printf("%d\n",A[N-1]);
    printf("%d\n",count);

    return 0;
  }
