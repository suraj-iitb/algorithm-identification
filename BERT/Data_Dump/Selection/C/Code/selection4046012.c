#include<stdio.h>
int main(){
  int A[100],N,i,j,minj,count = 0,b,c;
  scanf("%d",&N);
  for(i = 0; i < N; i++){
    scanf("%d",&A[i]);
  }
  for(i = 0; i < N; i++){
    minj = i;
    b = A[minj];
    for(j = i; j < N; j++){
      if(A[j] < A[minj]){
	minj = j;
      }
    }
    if(b!=A[minj])count++;
    b = A[i];
    c = A[minj];
    A[i] = c;
    A[minj] = b;
  }
  for(i = 0; i < N-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n%d\n",A[N-1],count);
  return 0;
}
