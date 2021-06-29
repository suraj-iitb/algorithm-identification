#include<stdio.h>

  void  show(int A[],int N){
    for (int i = 0; i < N; i++) {
      printf("%d",A[i] );
      if(i!=N-1)printf(" ");
    }
    printf("\n");
  }

  int insert(int A[],int N){
    int minj;
    int sw=0;
    int i,j;
    int s;
    for (i = 0; i < N-1; i++) {
      minj=i;
      for (j = i; j < N; j++) {
        if(A[minj]>A[j]) minj=j;
      }
      s=A[i];A[i]=A[minj];A[minj]=s;
      if(minj!=i)sw++;
    }
    show(A,N);
    return sw;
  }

  int main(){
    int A[100];
    int N;
    scanf("%d\n",&N );
    for (int i = 0; i < N; i++) {
      scanf("%d",&A[i] );
    }
    printf("%d\n",insert(A,N) );
    return 0;
  }
