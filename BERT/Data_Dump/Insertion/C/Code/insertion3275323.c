#include <stdio.h>

int main(){
  int N,v,i,j,k,A[100];

  scanf("%d",&N);
  if(N<1 || N>100){
    return -1;
  }

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
    if(A[i]<0 || A[i]>1000){
      return -1;
    }
  }

  for(i=0;i<N;i++){
    v = A[i];
    j = i-1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
      A[j+1] = v;
    }
    for(k=0;k<N;k++){
      printf("%d",A[k]);
      if(k == N-1) break;
      printf(" ");
    }
    printf("\n");
  }

  return 0;
}

