#include<stdio.h>

void selectionSort(int A[],int N){
  int i,j,temp,cnt=0,minj;

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
        minj=j;}
    }
      temp=A[i];
        A[i]=A[minj];
        A[minj]=temp;
        if(i != minj) cnt++;

    }

    for(i=0;i<N;i++){
      if(i>0) printf(" ");
      printf("%d",A[i]);
        }
    printf("\n");

    printf("%d\n",cnt);
}

  int main(){

    int N,i,A[100];

    scanf("%d\n",&N);
    for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

   selectionSort(A,N);


    return 0;
  }


