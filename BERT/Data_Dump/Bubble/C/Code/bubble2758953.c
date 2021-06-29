#include <stdio.h>

void trace(int A[],int N,int count){
  int i ;
  for (i = 0; i < N ; i++){
    if (i > 0) printf(" ");
    printf("%d" , A[i]);
  }
  printf("\n");
  printf("%d\n", count);
}

void bubblesort(int A[],int N,int count){
  int i ,j;
  int tmp;

  for(i = N ; i > 0; i-- ){
    for(j = N-1; j > N-i; j--){
      if(A[j] < A[j-1]){
        tmp = A[j];
        A[j] = A[j-1];
        A[j-1] = tmp;
        count = count + 1;
      }

    }
  }
  trace(A,N,count);
}


int main(){
  int N,i,count;
  int A[100];

  scanf("%d", &N);
  for(i = 0; i<N; i++)scanf("%d",&A[i] );

  count = 0;
  bubblesort(A,N,count);
  //trace(A,N,count);

  return 0;
}

