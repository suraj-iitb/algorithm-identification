#include <stdio.h>

int main(){

  int N,i,j,a,count,A[100];
  count=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;
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
