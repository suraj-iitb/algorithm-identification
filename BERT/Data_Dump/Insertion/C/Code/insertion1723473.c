#include<stdio.h>

int main(){
  int i, j, N, v, A[1000];

  scanf("%d",&N);
  for(i=0; i<N; i++){
    scanf("%d",&A[i]);
  }
  for(i=0; i<N; i++){
    v = A[i];
    j = i - 1;
    while(j>=0 && A[j]>v){
      A[j+1] = A[j];
      j--;
    }
    A[j+1]=v;
    for(j=0; j<N; j++){
      if(j<N-1)printf("%d ",A[j]);
      else printf("%d\n",A[j]);
    }
  }
  return 0;
}
      
