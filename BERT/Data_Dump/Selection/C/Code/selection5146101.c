#include<stdio.h>

int main(){

  int i,N,A[101],minj,j,t;
  int cnt = 0;

  scanf("%d",&N);

  for(i=0;i < N;i++)   scanf("%d",&A[i]);


  for(i=0;i < N-1;i++){
      minj = i;
    for(j = i+1; j < N;j++){
       if(A[j] < A[minj]){
        minj = j;
      }
    }
    if(minj != i){
          t = A[i];
          A[i] = A[minj];
        A[minj] = t;
        cnt++;
        }
          }


  for(i=0;i < N;i++){
    if(i == N-1){
      printf ("%d\n",A[i]);
    }
    else printf("%d ",A[i]);
  }

    printf("%d\n",cnt);

  return 0;
}

