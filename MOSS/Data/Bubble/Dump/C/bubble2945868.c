#include<stdio.h>
#include<stdlib.h>
int c=0;

int* Bubble(int N, int *A){
  int flag=1, j, num;
  while(flag){
    flag=0;
    for(j=N-1 ; j>0 ; j--){
      if(A[j]<A[j-1]){
        num=A[j];
        A[j]=A[j-1];
        A[j-1]=num;
        flag=1;
        c++;
      }
    }
  }
  return A;
}

int main(void){
  int N,i;
  int *A;
  scanf("%d",&N);
  A = (int*)malloc(sizeof(int)*N);
  for(i=0 ; i<N ; i++){
    scanf("%d",&A[i]);
  }
  A=Bubble(N,A);
  printf("%d",A[0]);
  for(i=1 ; i<N ; i++){
    printf(" %d",A[i]);
  }
  printf("\n%d\n",c);
  return 0;
}
