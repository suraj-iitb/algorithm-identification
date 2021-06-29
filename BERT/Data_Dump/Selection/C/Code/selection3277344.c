#include <stdio.h>
int main(){
  int i,j,N,count,minj,swap;
  int A[100];
  count=0;

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
    if(A[i]!=A[minj]){
      swap=A[i];
      A[i]=A[minj];
      A[minj]=swap;
      count++;
    }
  }

  printf("%d",A[0]);
  for(i=1;i<N;i++){
    printf("% d",A[i]);
  }
  printf("\n%d\n",count);

  return 0;
}

