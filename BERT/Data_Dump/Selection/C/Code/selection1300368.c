#include<stdio.h>
int main(void){
  int A[100],N,i,num=0,minj,j,mikio;
  scanf("%d",&N);
  
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
      // if(j==N-1 && A[i]<A[minj]){
	
      }
mikio=A[i];
	A[i]=A[minj];
	A[minj]=mikio;
	if(i!=minj)	num++;
    }
  

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[i],num);
  return 0;
}
