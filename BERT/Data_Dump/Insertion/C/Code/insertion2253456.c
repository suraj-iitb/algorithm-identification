#include <stdio.h>

int main(){
  int A[1000],i,v,j,N,f;

  scanf("%d\n",&N);
 
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N-1;i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[N-1]);
  
  for(i=1;i<=N-1;i++){
    v = A[i];
    j = i - 1;

    while(j >=0 && A[j]>v){
      A[j+1] = A[j];
      j = j - 1;
      A[j+1]=v;
    }
    for(f=0;f<N-1;f++){
      printf("%d ",A[f]);
    }
    printf("%d\n",A[N-1]);
  }
  return 0;
}
