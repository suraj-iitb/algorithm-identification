#include<stdio.h>



void trace(int A[],int N);
void insertsort(int A[],int N);




int main(void){

 
  
  int N,i,j;
  
  scanf("%d",&N);

  int A[N];
  for(i=0;i<N;i++){scanf("%d",&A[i]);}

  
  trace(A,N);
  insertsort(A,N);

    return 0;
}





void trace(int A[],int N){
  int i;
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");


}





void insertsort(int A[],int N){
  int j,i,v;
  int k;
  for(i=1;i<N;i++){
    v=A[i];
    j=i-1;
    while((j>=0)&&(A[j]>v)){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    trace(A,N);
  }
}

