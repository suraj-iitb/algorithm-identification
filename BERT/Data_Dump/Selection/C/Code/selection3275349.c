#include<stdio.h>

int main(){
  int i,j,A[100],N,temp=0,count=0,minj;
  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N-1;i++){
    minj=i;
    for(j=i;j<N;j++){
      if(A[j] < A[minj]){
	minj=j;
	
      }
    }
    if(i!=minj){
      temp=A[i];
      A[i]=A[minj];
      A[minj]=temp;
      count++;
    }
  }
  for(i=0;i<N;i++){
    if(i>0)printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
      
  

