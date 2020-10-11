#include <stdio.h>
#include <stdlib.h>
int main(){
  int N,i,j,n,*A,count=0,minj;
  scanf("%d",&N);
  A=(int*)malloc(sizeof(int)*N);
  for(i=0;i<N;i++)
      scanf("%d",&A[i]);
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){

	minj=j;
      }
    }
    if(i!=minj)
    count++;
      n=A[i];
      A[i]=A[minj];
      A[minj]=n;}
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1)
      printf(" ");
  }
  printf("\n%d\n",count);
  return 0;
}
