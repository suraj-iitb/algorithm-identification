#include <stdio.h>

void selectionSort(int [] ,int);

int main(){
  int i,N,A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  selectionSort(A,N);

  return 0;
}

void selectionSort(int A[] ,int N){
  int i,j,k,minj,tmp,count=0;

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj])
       minj=j;


    }
    if(i!=minj){
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    count++;
  }
  }

  for(k=0;k<N;k++){
    printf("%d",A[k]);
    if(k!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
}

