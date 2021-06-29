#include<stdio.h>

int main(){
  int A[100],N,i,j,a,count=0,temp;
  scanf("%d",&N);
  for(a=0;a<N;a++){
    scanf("%d",&A[a]);
  }
    for(i=0;i<N;i++){
      for(j=N-1;j>=i+1;j--){
      if(A[j]<A[j-1]){
	temp=A[j];
	A[j]=A[j-1];
	A[j-1]=temp;
	count++;
      }
     
    }
      if(i!=N-1){
       printf("%d ",A[i]);
      }
      else printf("%d",A[i]);
  }
    printf("\n%d",count);
    printf("\n");
  return 0;
}

