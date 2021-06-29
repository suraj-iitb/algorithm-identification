#include <stdio.h>

int main(){
  int i,j,n,N;
  int A[100];
  int flag,count=0;

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  
  flag=1;
  i=0;
  while(flag){
    flag=0;
    for(j=N-1; j>=i+1; j--){
      if(A[j]<A[j-1]){
	n=A[j];
	A[j]=A[j-1];
	A[j-1]=n;
	flag=1;
	count++;
      }
    }
    i++;
  }
  
  for(i=0; i<N; i++){
    printf("%d",A[i]);
    if(i != N-1) printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}

