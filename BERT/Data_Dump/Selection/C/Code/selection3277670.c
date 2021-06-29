#include<stdio.h>
#define MAX 100

int main(){
  int A[MAX];
  int i,j,minj,N,swap,count = 0;

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }

  for(i=0; i<N; i++){
    minj = i;
    for(j=i; j<N; j++){
      if(A[j] < A[minj]) minj = j;     
    }
    if(i!=minj){
    swap = A[i];
    A[i] = A[minj];
    A[minj] = swap;
    count++;
    }
  }

  for(i=0; i<N; i++){
    printf("%d",A[i]);
    if(i==N-1) break;
    printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}

