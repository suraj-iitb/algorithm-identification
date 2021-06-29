#include <stdio.h>

int main(){
  int i,j,N,A[100],minj,flag,k=0;

  scanf("%d",&N);

  for(i=0;i<N;i++) scanf("%d",&A[i]);

  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(A[i]>A[minj]){
      k++;
    }   
    flag=A[i];
    A[i]=A[minj];
    A[minj]=flag;
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i==N-1) break;
    else printf(" ");
  }
  printf("\n");
  printf("%d\n",k);
  
  return 0;
}
