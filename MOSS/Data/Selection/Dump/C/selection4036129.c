#include<stdio.h>
#include<stdlib.h>
int main(){
  int N,A[100],f=0,temp,i,j,minj;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j] < A[minj]){
	minj=j;
	  }
    }
    if(A[minj]<A[i]){
    temp=A[i];
    A[i]=A[minj];
    A[minj]=temp;
    f++;
    }
  }
  for(i=0;i<N;i++){
    if(i!=N-1)printf("%d ",A[i]);
    else printf("%d",A[i]);
   }
  printf("\n%d\n",f);
  return 0;
}
