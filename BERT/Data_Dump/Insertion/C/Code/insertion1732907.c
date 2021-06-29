#include <stdio.h>

int main(){
  int i,j,N,k;
  int key;
  scanf("%d",&N);
  int A[N];
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

    for(k=0;k<N-1;k++)
      printf("%d ",A[k]);
    printf("%d",A[k]);
    printf("\n");

  for(j=1;j<N;j++){
    key=A[j];
    i=j-1;
    while(i>=0&&A[i]>key){
      A[i+1]=A[i];
      i=i-1;
    }
    A[i+1]=key;
    for(k=0;k<N-1;k++)
      printf("%d ",A[k]);
    printf("%d",A[k]);
    printf("\n");
    
  }
  return 0;
}
