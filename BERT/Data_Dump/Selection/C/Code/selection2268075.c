#include <stdio.h>

int main(){

  int N,i,j,a,flag,count,minj,A[100];
  count=0;
  flag=0;
  
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj=j;
	flag=1;
      }
    }
    if(flag==1){
      count++;
      flag=0;
    }
    a=A[i];
    A[i]=A[minj];
    A[minj]=a; 
  }
  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }  
  printf("%d\n",A[N-1]);
  printf("%d\n",count);
  return 0;
}
