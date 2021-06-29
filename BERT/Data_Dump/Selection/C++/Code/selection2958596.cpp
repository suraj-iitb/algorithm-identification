#include<stdio.h>
int main(){

  int N,i,j,minj,eg,count=0;
  int A[100];

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<=N-1;i++){
    minj=i;
    for(j=i;j<=N-1;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(minj != i){
      eg=A[i];
      A[i]=A[minj];
      A[minj]=eg;
      count++;
    }

  }

  for(i=0;i<N;i++){
    if(i>0){
      printf(" ");
      
    }
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;

}

