#include <stdio.h>

int selectionSort(int A[],int N){
  int i,minj,c=0,j,t;
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])minj=j;
    }
    t=A[i];
    A[i]=A[minj];
    A[minj]=t;
    if(i!=minj)c++;
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

  c=selectionSort(A,N);

  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  
  printf("\n%d\n",c);

  return 0;
}

