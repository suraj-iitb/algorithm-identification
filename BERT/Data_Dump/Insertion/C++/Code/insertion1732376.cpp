#include <stdio.h>
int main(){
  int i,j,N,v,A[1000],k;
  
  scanf("%d",&N);
  
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
    }
    A[j+1]=v;
    for(k=0;k<N-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[N-1]);
  }
  return 0;
}
