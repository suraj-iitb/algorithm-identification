#include<stdio.h>

int bubbleSort(int *,int);

int main(){
  int N,i,cnt;
  int A[100];

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",&A[i]);

  cnt=bubbleSort(A,N);

  for(i=0;i<N;i++){
    if(i>0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",cnt);

  return 0;
}

int bubbleSort(int A[],int N){
  int i,j,cnt=0,tmp;

  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
        tmp=A[j];
        A[j]=A[j-1];
        A[j-1]=tmp;
        cnt++;
      }
    }
  }
  return cnt;
}
