#include <stdio.h>

int bubbleSort(int A[],int N){
  int c=0,j,a;
  int flag=1;

  while(flag){
    flag=0;
    for(j=N-1;j>0;j--){
      if(A[j]<A[j-1]){
	a=A[j];
	A[j]=A[j-1];
	A[j-1]=a;
	flag=1;
	c++;
      }
    }
  }
  return c;
}

int main(){
  int A[100],N,c,i;

  scanf("%d",&N);
  while(N<1||N>100){
    scanf("%d",&N);
  }

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  c=bubbleSort(A,N);

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  
  printf("\n%d\n",c);

  return 0;
}

