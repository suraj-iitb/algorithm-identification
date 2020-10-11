#include <stdio.h>

int main(){
  int i,N,j,A[100],v,k;
  scanf("%d",&N);
  if(1<= N && N<=100)
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
    if(A[i]>1000) break;
  }

  for(i=0;i<=N-1;i++){
    if(i!= N-1) printf("%d ",A[i]);
    else printf("%d",A[i]);
    }
printf("\n");

  for(i=1;i<=N-1;i++){
    v=A[i];
    j=i-1;
    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
      A[j+1]=v;
    }
    for(k=0;k<=N-1;k++){
      if(k!= N-1) printf("%d ",A[k]);
     else printf("%d",A[k]);
    }
    printf("\n");
  }
  return 0;
}
