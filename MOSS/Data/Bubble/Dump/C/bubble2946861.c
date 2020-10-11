#include<stdio.h>

int main(){
  int N,i,j,A[100],L,p=0;

  scanf("%d",&N);

  for(i=0;i<N;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<N-1;i++){
    for(j=N-1;j>i;j--){
      if(A[j]<A[j-1]){
	L=A[j-1];
	A[j-1]=A[j];
	A[j]=L;
	p++;
      }
    }
  }
  for(i=0;i<N;i++){
    if(i==N-1) printf("%d",A[i]);
    else printf("%d ",A[i]);
    
  }
  printf("\n");
  printf("%d",p);
  printf("\n");
}

