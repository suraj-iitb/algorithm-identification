#include<stdio.h>

int selectionSort(int *,int);

int main(){
  int A[100];
  int i,N,cnt;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  cnt=selectionSort(A,N);

  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

int selectionSort(int A[],int N){
  int i,j,minj,tmp,cnt=0;

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]) minj=j;
    }
    tmp=A[i];
    A[i]=A[minj];
    A[minj]=tmp;
    if(i!=minj) cnt++;
  }
  return cnt;
}

