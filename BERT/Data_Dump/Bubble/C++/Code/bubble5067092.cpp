#include <stdio.h>
int main(){
  int A[100],flag=0,N,i,j,k;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
  for(j=N-1;j>=i+1;j--){
    if(A[j]<A[j-1]){
      k=A[j-1];
      A[j-1]=A[j];
      A[j]=k;
     flag++;
    }
  }
  }
  for(i=0;i<N;i++){
    if(i!=N-1)printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }
  printf("%d\n",flag);
    }
