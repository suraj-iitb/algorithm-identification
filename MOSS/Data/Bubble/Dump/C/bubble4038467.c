#include<stdio.h>
#include<stdlib.h>
int main(){
  int flag,a,N,i,j,*A,cnt=0;
  scanf("%d",&N);
  A=malloc(N*sizeof(int *));
  flag=1;
  for(i=0;i<=N-1;i++)scanf("%d",&A[i]);
  
  while(flag){
    flag=0;
  for(j=N-1;j>=1;j--){
    if(A[j]<A[j-1]){
      a=A[j];
       A[j]=A[j-1];
      A[j-1]=a;
      flag=1;
      cnt++;
    }
   
    
  }
  }
 
  
    for(j=0;j<N-1;j++)printf("%d ",A[j]);
  
  printf("%d\n",A[N-1]);
  printf("%d\n",cnt);
  free(A);
  return 0;
}

