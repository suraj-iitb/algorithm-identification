#include<stdio.h>

int main(){

  int A[100],N,i,j,temp,tempcount=0,minj;

  scanf("%d",&N);
  
  for(i=0 ; i<100 ;i++){
    A[i] = 0;
  }
  
  for(i=0 ; i<N ; i++){
    scanf("%d",&A[i]);
  }  

  for(i=0 ; i<=N-1 ; i++){
    minj = i;
    for(j=i ; j<=N-1 ; j++){
      if (A[j] < A[minj]) minj = j;
    }
    if(i != minj) tempcount++ ;
    temp = A[i];
    A[i] = A[minj];
    A[minj] = temp;

  }
    for(i=0 ; i<N ; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n%d\n",tempcount);
  return 0;
}

