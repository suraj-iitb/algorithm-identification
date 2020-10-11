#include<stdio.h>

int main(){
  int N,i,j,count=0,A[100],minj,k,l=1,m;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }
  /*for(i=0;i<N;i++){
    printf("%d ",A[i]);
    }*/
  for(i=0;i<N;i++){
    minj=i;
    for(j=i;j<N-1;j++){
      if(A[minj]>A[j+1]){
	minj=j+1;
	
      }
    }
    if(minj!=i){
      k=A[minj];
      A[minj]=A[i];
      A[i]=k;
      count++;
    }
  }
  for(i=0;i<N;i++){
    printf("%d",A[i]);
    if(i<N-1)printf(" ");
    else if(i==N-1)printf("\n");
    }
  printf("%d\n",count);
  return 0;
}
      
  

