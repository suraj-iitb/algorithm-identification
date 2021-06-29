#include <stdio.h>

int main(){
  int i,A[100],v,N,j,k,l;
  scanf("%d",&N);
  for(i=0;i<=N-1;i++){
    scanf("%d",&A[i]);
   }
  for(i=0;i<=N-1;i++){
     if(i==N-1) printf("%d",A[i]);
      else printf("%d ",A[i]);
  }
  printf("\n");
   for(i=1;i<=N-1;i++){
      v=A[i];
    j=i-1;
    while(j>=0&&A[j]>v){
      A[j+1]=A[j];
    j--;
    A[j+1]=v;
    }
    for(k=0;k<=N-1;k++){
      if(k==N-1) printf("%d",A[k]);
      else printf("%d ",A[k]);
        }
    printf("\n");
 }
  return 0;
}

