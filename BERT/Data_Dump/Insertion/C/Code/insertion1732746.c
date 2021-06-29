#include<stdio.h>

int main(){

  int A[1000];
  int N = 0;
  int i,j,key,length;

  scanf("%d",&N);

  for(i = 0; i < N; i++){

    scanf("%d",&A[i]);

  }

  for (i =0; i < N; i++){

    key = A[i];

    j = i - 1;

    while(j >= 0 && A[j] > key){

  A[j + 1] = A[j];

  j = j - 1;

}

A[j + 1] = key;

  for(length = 0; length < N-1; length++){
    printf("%d ",A[length]);
  }
  printf("%d\n",A[N-1]);
  }

return 0;

}
