#include<stdio.h>

int main(){
  int A[100];
  int i,j,N,k;
  int change=0;

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	k=A[j];
	A[j]=A[j-1];
	A[j-1]=k;
	change++;
      }
    }
  }

  for(i=0;i<N-1;i++)printf("%d ",A[i]);

  printf("%d\n",A[i]);
  printf("%d\n",change);


  return 0;
}
