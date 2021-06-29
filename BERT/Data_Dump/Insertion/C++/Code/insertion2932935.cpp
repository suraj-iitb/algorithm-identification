#include<stdio.h>

//配列の出力
void Outsort(int A[],int N){
  int i;
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}

//挿入ソート
void insertionSort(int A[],int N){
  int i, j, v;
  for(i=0;i<N;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j] > v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    Outsort(A,N);
  }
}

int main(){
  int N, i, j;
  int A[1000];

  scanf("%d",&N);
  if(N>100||N<1)return 0;
  for(i=0;i<N;i++) scanf("%d",&A[i]);


  insertionSort(A,N);
  
  return 0;
}



