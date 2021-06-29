#include<stdio.h>
int main(){
  int i=0,j=0,k,N,a,v;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  for(k=0;k<N;k++){
    if(k==N-1) printf("%d",A[k]);
    else printf("%d ",A[k]);
  }
  printf("\n");
  for(i=1;i<=N-1;i++){ 
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    for(j=0;j<N;j++){
      if(j==N-1) printf("%d",A[j]);
      else printf("%d ",A[j]);
    }
    printf("\n");
  }
  return 0;
}

