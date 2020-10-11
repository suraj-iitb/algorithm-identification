#include<stdio.h>
#include<stdlib.h>
int main(){

  int N,A[100],i,j,temp,minj,count=0;
  scanf("%d",&N);
  for(i=0;i<N;i++)scanf("%d",&A[i]);
  
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]){
	minj=j;}
      }
    if(i!=minj){
      temp=A[minj];
      A[minj]=A[i];
      A[i]=temp;
     
      count++;
    }
  }
  for(i=0;i<N-1;i++){printf("%d ",A[i]);}
  for(i=N-1;i<N;i++){printf("%d",A[i]);}
  printf("\n");
  printf("%d",count);
  printf("\n");
  

  return 0;
}
