#include<stdio.h>
int main(void){
  int A[100];
  int i,j,N,key,C;
  C=0;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N;i++){
    for(j=N-1;j>i;j--){
      key=A[j];
      if(A[j]<A[j-1]){
        A[j]=A[j-1];
        A[j-1]=key;
        C++;
      }
    }
  }

  for(i=0;i<N;i++){
      if(i!=0)printf(" ");
      printf("%d",A[i]);
    }
  printf("\n");
  printf("%d\n",C);

  return 0;
}
