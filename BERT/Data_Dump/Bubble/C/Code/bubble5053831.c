#include<stdio.h>
#define MAX 100
int main(){
  int A[MAX],N,i,j,B,x=0;
  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
        B=A[j];
        A[j]=A[j-1];
        A[j-1]=B;
        x++;
      }
    }
  }
  for(i=0;i<N;i++){
    if(i!=N-1)printf("%d ",A[i]);
    else printf("%d\n",A[i]);
  }
  printf("%d\n",x);
  return 0;
}
