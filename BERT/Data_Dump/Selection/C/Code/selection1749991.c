#include<stdio.h>
 
int main(){
  int N,A[100],i,j,tmp,t=0,minj;
 
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
 

  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj=j;
	
      }
      
       
    }
    if(i!=minj){
      tmp=A[i];
      A[i]=A[minj];
      A[minj]=tmp;
      t++;
    }
  }
  
  for(i = 0;i<N-1;i++)
    printf("%d ",A[i]);
  printf("%d\n%d\n",A[N-1],t);
  
  
  return 0;
}
