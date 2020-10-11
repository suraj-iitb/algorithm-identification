#include<stdio.h>

int main(){
  int N,i,j,A[100],minj,p=0,L;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N-1;j++){
      if(A[minj]>A[j+1]){
	minj=j+1;
      }
    }
    if(minj!=i){
      p++;
      L=A[i];
      A[i]=A[minj];
      A[minj]=L;
    }
  }
  for(i=0;i<N;i++){
    if(i==N-1) printf("%d",A[i]);
    else printf("%d ",A[i]);
    
  }
  printf("\n");
  printf("%d",p);
  printf("\n");
  
  return 0;
}
    

