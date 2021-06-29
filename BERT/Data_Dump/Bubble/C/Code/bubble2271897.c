#include <stdio.h>

int main(){
  int N,i,j,count=0,sw;

  scanf("%d",&N);
  int A[N];
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
    }
    for(i=0;i<N-1;i++){
      for(j=N-1;j>i;j--){
            if(A[j]<A[j-1]){
              sw=A[j-1];
              A[j-1]=A[j];
              A[j]=sw;

              count++;
            }
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i!=N-1) printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
    return 0;
  }
