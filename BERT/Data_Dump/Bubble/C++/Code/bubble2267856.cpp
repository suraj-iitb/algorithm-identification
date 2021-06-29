#include<stdio.h>

int main(){
  int flag=1,i,j,a,count=0;
  int N,A[100];
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);

  }
  while(flag){
    flag=0;
    for(j=N-1;j>=1;j--){
      if(A[j]<A[j-1]){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;
	flag=1;
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
