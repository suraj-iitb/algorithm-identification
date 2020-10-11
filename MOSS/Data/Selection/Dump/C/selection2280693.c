#include <stdio.h>

void selectionSort(int *,int);

int main(){

  int N,i;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  selectionSort(A,N);

  return 0;

}

void selectionSort(int A[],int N){
  int i,j,tmp,n=0,minj;

  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]) minj=j;
    }
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    if(A[i]<A[minj]) n++;
  }


  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",n);

}
