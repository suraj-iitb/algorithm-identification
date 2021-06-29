#include <stdio.h>

void bubbleSort(int *,int);
void trace(int *,int);

int cnt=0;

int main(){
  int N=0,i,j;
  int A[100];

  scanf("%d",&N);
  for(i=0; i < N; i++){
    scanf("%d",&A[i]);
  }
  
  bubbleSort(A,N);

  return 0;
}

void trace(int *A,int N){
    int i;
    
    for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i != N-1)printf(" ");
    }
    printf("\n");
    printf("%d\n",cnt);
}

void bubbleSort(int *A,int N){
  int i,j=0;
  int tmp;
  //printf("hoge");
  for(i=0;i<N;i++){
    //printf("hoge2");
    j=N-2;
    while(j>=i){
      //printf("hoge");
      if(A[j]>A[j+1]) {
	tmp=A[j+1];
	A[j+1]=A[j];
	A[j]=tmp;
	cnt++;
      }
      j--;
    }
  }
  trace(A,N);
}

