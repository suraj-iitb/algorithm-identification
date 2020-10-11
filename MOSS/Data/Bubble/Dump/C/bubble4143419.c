#include<stdio.h>


void bubbleSort(int A[],int N){
  int i,j,temp,cnt=0;

  for(i=0;i<N-1;i++){
    for(j=N-1;j>=i+1;j--){
      if(A[j-1]>A[j]){
        temp=A[j-1];
        A[j-1]=A[j];
        A[j]=temp;
        cnt++;
      }
    }
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

    bubbleSort(A,N);


    return 0;
  }


