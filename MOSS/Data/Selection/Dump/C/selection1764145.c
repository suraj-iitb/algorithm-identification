#include<stdio.h>
int main(){
  int n=0,N,i,j,A[100],minj,tmp;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    tmp= A[i];
    A[i] = A[minj];
     A[minj] = tmp;
    if(i != minj)n++;
  }
 for(i=0;i<N-1;i++){
   printf("%d ",A[i]);
 }
 printf("%d",A[N-1]);
 printf("\n%d\n",n);
  return 0;
}
