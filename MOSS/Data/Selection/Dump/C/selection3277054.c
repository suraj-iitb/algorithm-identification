#include <stdio.h>

int Ssort(int *,int);

int main(){
  int A[100],N,i,count;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);
  count=Ssort(A,N);
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

int Ssort(int *A,int N){
  int i,j,x,count=0,minj;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]) minj=j;
    }
    x=A[i];
    A[i]=A[minj];
    A[minj]=x;
    if(i!=minj)count++;
  }
  return count;
}

