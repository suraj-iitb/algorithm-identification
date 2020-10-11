#include<stdio.h>

int bubble(int A[],int N){
  int sw = 0;
  int i,j,temp;

  for(i=0;i<(N-1);i++){
    for(j=(N-1);j>i;j--){
      if(A[j]<A[j-1]){
	temp=A[j-1];
	A[j-1]=A[j];
	A[j]=temp;
	sw++;
      }
    }
  }
  return sw;
}

int main(){
  int A[100],N,i,sw;

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  sw = bubble(A,N);

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",sw);

  return 0;
}
